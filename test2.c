#include <stdlib.h>
#include <stdio.h>

static char currentToken[4096];
static size_t currentTokenLength;

static
void addCharToCurrentToken ( char c ) {
	if (currentTokenLength < sizeof(currentToken)) {
		currentToken[currentTokenLength++] = c;
	}
}

static
void printCurrentToken ( ) {
	printf("Token: >>>%.*s<<<\n", (int)currentTokenLength, currentToken);
	currentTokenLength = 0;
}


typedef enum {
	STATE_FindStartOfData,
	STATE_FindStartOfToken,
	STATE_ParseNumber,
	STATE_ParseString,
	STATE_CheckEndOfString,
	STATE_FindDelimiter,
	STATE_ParseError,
	STATE_EndOfData
} ParserState;


ParserState parserState = STATE_FindStartOfData;


static
void runTheStateMachine ( ) {
	while (parserState != STATE_ParseError
		   && parserState != STATE_EndOfData
			) {
		int c = fgetc(stdin);
		// End of data?
		if (c == -1) {
			switch (parserState) {
				case STATE_ParseNumber:
				case STATE_CheckEndOfString:
					printCurrentToken();
					parserState = STATE_EndOfData;
					break;

				case STATE_ParseString:
					// Data ends in the middle of token parsing? No way!
					fprintf(stderr, "Data ended abruptly!\n");
					parserState = STATE_ParseError;
					break;

				case STATE_FindStartOfData:
				case STATE_FindStartOfToken:
				case STATE_FindDelimiter:
					// This is okay, data stream may end while in these states
					parserState = STATE_EndOfData;
					break;

				case STATE_ParseError:
				case STATE_EndOfData:
					break;
			}
		}

		switch (parserState) {
			case STATE_FindStartOfData:
				// Skip blank lines
				if (c == '\n' || c == '\r') break;
				// !!!FALLTHROUGH!!!

			case STATE_FindStartOfToken:
				// Skip overe all whitespace
				if (c == ' ' || c == '\t') break;
				// Start of string?
				if (c == '"') {
					parserState = STATE_ParseString;
					break;
				}
				// Blank field?
				if (c == ',') {
					printCurrentToken();
					break;
				}
				// End of dataset?
				if (c == '\n' || c == '\r') {
					printf("------------------------------------------\n");
					parserState = STATE_FindStartOfData;
					break;
				}
				// Everything else can only be a number
				parserState = STATE_ParseNumber;
				addCharToCurrentToken(c);
				break;

			case STATE_ParseNumber:
				if (c == ' ' || c == '\t') {
					// Numbers cannot contain spaces in the middle,
					// so this must be the end of the number.
					printCurrentToken();
					// We still need to find the real delimiter, though.
					parserState = STATE_FindDelimiter;
					break;
				}
				if (c == ',') {
					// This time the number ends directly with a delimiter
					printCurrentToken();
					parserState = STATE_FindStartOfToken;
					break;
				}
				// End of dataset?
				if (c == '\n' || c == '\r') {
					printCurrentToken();
					printf("------------------------------------------\n");
					parserState = STATE_FindStartOfData;
					break;
				}
				// Otherwise keep reading the number
				addCharToCurrentToken(c);
				break;

			case STATE_ParseString:
				if (c == '"') {
					// Either this is the regular end of the string or it is just an
					// escaped quotation mark which is doubled ("") in CVS.
					parserState = STATE_CheckEndOfString;
					break;
				}
				// All other chars are just treated as ordinary chars
				addCharToCurrentToken(c);
				break;

			case STATE_CheckEndOfString:
				if (c == '"') {
					// Next char is also a quotation mark,
					// so this was not the end of the string.
					addCharToCurrentToken(c);
					parserState = STATE_ParseString;
					break;
				}
				if (c == ' ' || c == '\t') {
					// It was the end of the string
					printCurrentToken();
					// We still need to find the real delimiter, though.
					parserState = STATE_FindDelimiter;
					break;
				}
				if (c == ',') {
					// It was the end of the string
					printCurrentToken();
					// And we even found the delimiter
					parserState = STATE_FindStartOfToken;
					break;
				}
				if (c == '\n' || c == '\r') {
					// It was the end of the string
					printCurrentToken();
					// And we even found the end of this dataset
					printf("------------------------------------------\n");
					parserState = STATE_FindStartOfData;
					break;
				}
				// Everything else is a parse error I guess
				fprintf(stderr, "Unexpected char 0x%02X after end of string!\n", c);
				parserState = STATE_ParseError;
				break;

			case STATE_FindDelimiter:
				// Delemiter found?
				if (c == ',') {
					parserState = STATE_FindStartOfToken;
					break;
				}
				// Just skip overe all whitespace
				if (c == ' ' || c == '\t') break;
				// End of dataset?
				if (c == '\n' || c == '\r') {
					// And we even found the end of this dataset
					printf("------------------------------------------\n");
					parserState = STATE_FindStartOfData;
					break;
				}
				// Anything else a pare error I guess
				fprintf(stderr, "Unexpected char 0x%02X after end of token!\n", c);
				parserState = STATE_ParseError;
				break;

			case STATE_ParseError:
				// Nothing to do
				break;

			case STATE_EndOfData:
				// Nothing to do
				break;
		}
	}
}

int main ( ) {
	runTheStateMachine();
	return (parserState == STATE_EndOfData ? 0 : 1);
}