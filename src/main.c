/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:52:50 by tterribi          #+#    #+#             */
/*   Updated: 2022/11/05 11:25:19 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	fancy_init(void)
{
	printf ("\033[0;36m");
	printf("\t███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗\n"
		"\t████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║\n"
		"\t██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║\n"
		"\t██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║\n"
		"\t██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗\n"
		"\t╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝"
		"╚══════╝\n");
	printf("\033[0m\n");
	printf("\033[0;35m");
//	printf("\t\t    |̸̨̨̡̡̨̢̡̢̡̢̧̡̧͎̯̦̜̦̭̼͉͉̺̠̭̫̱̼̪̪̭̯̖̜̱̬̪͓̼͖̩̹̘͖͖͔̝̠̹̞̣̞̳̞̻̥̜̰͖͍̘͉̞̮̪̹͇̣͙̳͇̜̭̯͍̰̖̺̯͕̪̜̤͓͓̺̪̱̤̲͈̤͕̫̫̲̪̯̣̬̼̟̞̟̹̩̱̼̦̥̙̺̼̭̦͖̞̲͙̦̗̬͇͓͉̬͙̥̤̺̳̩̳͎̺͕̹̗̬̱̟̰̤̹͖̹̫̘̳̦̝̦͚̬̼̝͇̮͍̜̝̦̠̼̯̗̗̺͖͈̩̞̦̰͈̥̰̪̜̩͖̦̭̗̰͙̫̘̼͎̐̂͛̌̊́̋̀͋̅̂̓͒͑͗͊̉̒͋̃͗́̉͐̐̋̈́̓̉̅̾̀̽̉͛̂̆̿̍̒͐͐̒̓͐͊͋̈́̋͒͛̄͋̂̕̕̚̕̚͜͝͝͝͝ͅͅͅͅH̶̢̧̢̨̡̧̨̢̨̨̨̢̢̡̢̡̨̡̛̛̛̛̛̛̛̛̛̛̳͇̪̣̻̩̤͓̣̺̭̝̱̻̺̞͖̥͙͍̩̱̯̟͎̤̲̦̰̻̪͈̬̦̖̹͕͍̭͙͓͍̩̩̙̬͙͔̳͇̫̩̮̲̯̱̰͉̙̺̮͚̪̦̜͍̩̭͙͖̙͍̼̜̬̤͍̣͇̣̹̻̝̪̲̤̥͙͈̝̩̤͖̻͓͙̬̝̪͈̲͇̻̫̪̣̠̤͓̙̠̤̮̗͎̟͕̮͔̥̦͔̲̱̦̜̱̩̖̠̺͍̜̞̠͙̟̱͈̜̞͉̙̘̜̝̫͈̝̭̲̣̬̯͇̘͍̮̦̝̜͙͚͍̩͓̙̭̪̪̤̖̦͙̣̼̺̳̻̘̤͚͍̭͍̫̱̦͙͍̺̻͙̬͎̺͚͉̪̠̱̮̻̱̣̘̥̯̩̟̬̹̫̩̻̪̟̠̙̘̲̒̃̒̆̉͂͂͋̓̀̀͛́̂̏̋̀̀͑͒̾͂̈́̓͌̏̑̋̇̏̀̈̏͒͛͑̒̈͊̎̿̽̊͆̀̄͆̌̃͋̓̑͌̌́̒͊̉̏́͑̐͌̃̉̋̇̃̎̅̽̌͂̆̉͆̒̐̈̂̉̆́̒̓̍̀̐͑̓̀͊́͋̽̑̾͂̀̑͑̄̇̑̍̐̄̇́̈́̍̈́̔͐͐͑̐̓́̀͊͗̉͒̈̃̊͌́̓͒͂̇̀̓͛̎̓̌̔̎͊̓̋͆̃͆̎͋̎͂̇͌̇̈͊̌̈́̊̓̃̉̇̀̈́̈̆̊͋͌̿͋̇̆͆̈́̀͐́̓̄͋̀͋̃̀̌̔̌͐͊̋͌́̂͂̃́̾͘̕̚͘̕̚̚͘̚͘̕͘͘̕̚̚̕͘̚̕͘̚̕͘͜͜͜͜͠͝͝͝͝͠͝͝͝͝͝͝͠͝͝͝͝͠͝͝͝͠͠ͅͅͅͅơ̴̛̛̛̻͉͛̆̊͐̒̈́̐͑̓͗̍͋̒̈́͗̍͑͒̍́̍̇͒̓͗͐̐̌̄̈́̊̔̾̋̂̀́́̄̿͂͑̅̎͋͋̉̊̂͂͑͊̀́̋̀͂̉̄͌̑̾͐̌̇͛̂͊̈́̉̏͗̐̑̌̒̐́͂̈̀̅̈͌̑̃̾͂̑̎͊̍̓̇̐̉͒͑̅̒̏̂̾͂̀͋́̍̆͑́̐̀̎̓̽͊̽͗͋̉͆̊̽́̃̉̇̈́̌̑́̔̈́̇́̀̄͌́̋̏̇̒̄̔͌́̎̌̈́̍͒̏͊͛̆̀̀̎̽́̀́͆̇͊̈́̔̈́̒̽̅̇̈̽̈́̿̈̈́̈́̃͒̔̃̆̀͌͛̅̊̌̂͒̏̎̿͋̽̄̓͆́̄̀͛̓͛̀̓͗̏̂̿́̌͂̄́́̀͊͆͐̅̍̊͐̚̚͘̚̕̚͘͘̚̕̕̕͠͝͝͠͠͠͝͠͝͝͠͝͝͝͝͝͝͠p̷̢̨̧̨̢̧̨̨̛̛̛͙͙̣͕̙͍̼̤̪̭̳̺̜̰̫̱̹̦̭̙̣̣̬̙̣̻͈̻͎͉̹̬͚̰͖̝͍͇̼̻̬̳̗̗͙͍̳͖͖͎̦̯͕̬̺̝̘̬̯͍͚̺̜͎̻̱̥̹͔̹͍̫̅̐͌̐͌̍́̃́͊̑̇̒̿̎͆͒̈́͐̈́͊̔͒͐͐̏͋̈̈̌̑͆̓͑̎́̎̀͆̑͌̊̑̍̌̃́͗̀͗̇̌̽͌͊́̾̈́̆̂͒̿͂̍̎̐̎͑̀̆̊̾̀͒̊̅̈͗̅͒̀̇̎̏̔̆͌̎̉̏̀̅͐̍̆̉̎̉̉̅̉̀̌͌̒̀͊̔̊͑̀́̀̎͋̈́̓̃̆̀̃̽̐͗̉̍̅̍̃̐̈́̎̕͘̕͘̚̕͘͘͘̕͜͠͠͝͠͠͠͝͝͝͝͝͠͝ͅͅͅe̶̡̨̡̨̢̨̡̧̡̧̢̨̧̨̡̧̧̨̡̢̡̧̡̢̢̡̨̛̹̝̩̙͉̙̳̙͖̟̥͇̳̠̭͖͇̝͍̙̳̰̣̝͉͓͙̪̻͚͈̭̦̞̝̻̦̭̮̙̤̗͕̲̠̺̹̗̯̘͉̙̮͕̟̫̙͈͖̲͚̮̞̘̠̰̼̦̭͉̫͍̤̯̫̱͎͕͔͇͓̳̜͙͓͍̹͇͍̖̻̱̭͓̱͈̪͖͈̱̠̼͚̜̦̯̗̟̟̦̙̱͔̬̙͚̫̪̥̪̭̰͖̣̱̞̭̖͙̟͓̜̦͕͈̙̗̦͉̯̣̥̩̣̹̹͚̟̗̰̹̪̣̭̹̱͉̞͖̥͉̠̪͈͓̜̙͉̞̩̼̙͖̣͕̮̗̱̺̼̬͔̠̠̳̰̯̣̼͖̪̥̹̬̳̙̦̪̜̝̳̖̗̰̬͖̰̹̘̰̖͓͉̱̜̰͈͙͕̘̫͖̘͍̙̭̱̯̪̣͚͓̼̙̰̞͆̈́̄͂̾̀̈́̀̓̎͌̉͒̆̂̎̐́͌́͊̌̾̉̽͌͗̈́͋̍̽̇̀͗̄̍̀͊͒́͗͒̔̎̋́̍̽̆̈́͑͊̔̽͛̆̍̒̐̍̀̍̔̅̿̂̓̿͆̈͐̈́̐͒̏͂̔͐̈́͂͊̄̄̇̀͒͗̓̐̾̓̀͒͑̈́̽͒̏̂̉̓̈́̾̍̕͘͘̚͘͜͜͜͜͜͜͝͠͝͝͝͝͝͝͝͝͠ͅͅͅͅͅͅf̸̧̧̢̢̢̧̢̡̡̢̧̡̨̡̢̡̡̧̨̡̢̛̛̗̠̱̩̤͕̪̰͕̗̭̲̙͚͔͎͚͓͈̰̙̙̥̱̞͍̘̩̱̪̲̝͚̺͉̘͖̪͈̩̞͕̤͔͍͖͈͖̞͈͇͇̹͖̱͕͙̪̝͖͎͈̹̱͚̺̞̖͈̦̜̠̻̟̯͕̻̘̬̰͚̞̰͈̠̯̲͔̼͙͖̤̭̺̥̼̞̟̲̯̗̘̭͔̘̰͕̹̱̘͖͇̦͍̮͚͈̖͈̣͎̻̰͖̫̻̟͍̤̲͈̯͉̹͚̭͓̠̲̼̺͕͍̫̪̙͉̘̺͈̣̫͚̖̣̺̯̯̮̤̲͕̤̦̖̫̲̪͕̗̜͓̺̞͔̳̹̳͓̜̱͕͔̺̫̺̠̘̜̼͚̹͎̩̺̟̦̥̰̮̜̯͈̹͔̦̘͚̱̖̪̮̥̯̰̯̹̺̭̦͎̪̯̉́̿̈́͊̽̋̃̐̏̍̈́́͋́̎̍̿̐͐́̽͂͗͊̒̿͐͋́͒͐̀̒͂̊̍́͆̀̈́̓̉̏̈͊̅̾͆͗̊̓͑̇̇̋͛̎̆͛̿̈͌̓̿͐͒͑̈́̈̋̄̉̿̑̎̅̑͒͛͌̐͐͋́̒́̀͛͑̍̈͊́͒̓͐̈́͗̈́̈́̎͋́̀́͑̍̉̔̒́̈͌̂͑̄̏̅̅͆̆͊̃̀̀̀̈́̈́̔̽̚̕͘̕͘̚͘͘͘͜͜͜͜͜͜͝͝͝͝͠͠͝͝͝͠͠͝͝͠͝ͅͅͅͅͅͅͅư̴̛̛̱̲͇̙͇̿͂̿̃̌̒̈́̽̌͂̽̂̈̂̓͒̀̍͋̇̒̒̏̈́̔̌̈́̈́͌̿̔͊̊̈̊̏͋͗̆̓͗̓̀̈́̒͒̈́̄͋̉̃̌̍̉̐̋͒̌̀̃͗̊͆͐̍͐̽͊̓̎̈́̄̿͆͗̍̃͑̿̅̅̋͂͗͐̀̄̋̔́̑̉̃̍̓̈̍̽͊̄͛̑̀͗͐́͗̌̉́̆̎̐̅̌̐͗̇͌̐͗͗̑̾̑͑̇̽͆̿͘̚̚̚͘̕̚͝͠͝͝͝͝͝͝͝͝͝͝͝͝ļ̷̨̧̧̧̨̨̡̡̡̧̨̡̧̧̡̨̡̡̧̨̨̛̛̛̛̛̛̛͔̙̭̙͇̗͕̻͓̲̦͇̹̱̮̺̖͈̫̱͍̱͖̘̱̺͔͔̞̺͎̰͎̞̥̠̮͚͉̼͕̤͕̳͈̞̩̣̯̤̥̰̫̫͖̬̥̞̫̯̜̦̜̜̜̦͚̖̘̪̼̤̘͇̮̝̳̳̦̟̼̰͉̼̤͓͖̦̳͓̭̱͕̟͖̭͇̣̹͔̳͕̙̬̥̘̼͈͓͔͍̙̹̳̻͎̤̦̪̙̹̗̖̥͍̜̗͍͕̩͚͍͍͎͔̰̳͇̟̱͖̥̦̲̮̺͇̣̹́̎̓̌́̑͆̓̐͗͒͒͆̊̓͐̀͛̃̅̑̈̈́͌͋̒̉͗̿̈́͆̏͒̇̎̓̊̂̔̾̄͌̆́̌̅͛̂̔̌͗̄̽̈́̂̂̇̿͊͋͗͑̅̉͐̈́̈̍́̆́̈́̌̂̍̀͒̆͊́̀̾̈́́̌͂̊̽̌̍̈́̇̇͂͑͐̎̌̌̀̑̔̆͌͂͒̽͛̽͛̓́̽̒̀̑͐̌̊̄̆̈̏́̆̅̌̆̿͆͊͐̒͌́̑́̒̎̇̑́̎̓̉̒̓͊́̃̄͒̎͗̎͂̄͋̅͛́̉͊͒̃͌͑̈͂͋̄̋̊͌̅̆̒̊͋̓͊̅̇͂̀͐̋̅̉͋̔́̍͌́́̔̓̔̈́͌́͂̍͒͑͒́̅͌̈̓̆̀̋͗̽̉̃͆̀̀̀̕̕͘̕͘̕̕̚͘͘͘̚͘̚͘͘͜͝͠͠͝͠͝͠͠͝͠͝͝͠͠͝͠͠͠͝ͅͅͅl̵̨̢̢̧̡̨̢̛̛̛̛̛̞̻͉̰̺̙̟̹̠̙̫̥̯̱̠̬̥̤͉̩̘̥̦̩̪̝̙̮̦͍̱̳̮̲̭͍̜͈̝̥̞͚͕̭͚͚̞͉͍̺̳͉͔̥̟͚̝̼̝̝̺͓̰̞̦̭̮̺̙̼͖͔̪̣͕̫̜͓̣͖̯̦̥͈̠͕͉͉̭͇͈͙̳͔̭̖̘̣͖̤͖̒̋̌̈͊̓͐̔̓̽͐̿͗͒͐͂̆̾̑̊̐͂̍̀̀͋̊͒̊͗͋͗̄͊̍͗̀́̓̌̂̀̍̅͌̈́͌͊̈́̋̍͊̄̽̇͋͂̅̄̃̌̊͐̊͌̅̈́̔́̏̀̅̆̀͌̎͊̀̽̈́͆̒͋̌̒̃͆̈̔̊̇̀̔̎̆̎̃́͗́̒͆̔̋̇̈́͑͋́̇̇̔́͗̑̋̏̂͌̇̂̌͐̅̎̑̿͑̄̐̅͊̐͒̋̄̑̉̀̽̍͛͆͂̌̏̉͗̊̿͋̌̈́̀͗̄͋̚̕̕̕̕̚͘̚̚͘͘̕̕͘͜͠͝͠͠͝͝͝ͅͅý̶̢̡̧̧̡̨̧̧̡̨̡̡̡̢̢̨̡̡̧̧̧̛̛̛̛̫̠̩̺̘͖̻͇͖̣̞͍̪̳͕͈̣̱͕̣̦̜̯̼̲̘̞͔͚̳̘̰̠͕͓̼̺̤̬̞̹̞̱̼̹̬̪̠̪͙̗͎̮̞̬̘̹͓̩̲͎̥̲̥̭̝̤͔̗͔͙̠̝̯͓̖̭̫̮̺͚̯͎̪̤͙͈̹̲͈̻̻̥͇̭̫͈͔̯͔̹̣̗̲̫̘̪̦̹̣̹̤̪͓̝̙̞̰̱̤̝̦̟͕̬̩͔̫͙͙̦͎̘̭͎͔͙̫̬̝̼̜̻͕͈̤͍̱͔̪̰͍͕̳̹̯̬̼͖̙̫̲̠̫͓͔̪̼̤̫̟̮̪͖͇̼̘̯̘̣͋̔̄̊̇̿̿̆̈́̃̉̆̈̇̄̊̏̏̐̀͂̇̏͋̓̇̿̋̽̒̉̀́̅̊̇̓̏͗̈͐̌̌̇̑̈́̓̏̈̐̅͊̎̏̑̏̆̉̄̓̈́̍̎͆̏̿͗̈̽̓̐̀̇̈̓̈̉̇̑̓͂̈͊̔̓̔̂͆͗̋͑̀͋́͌̇͐̓̌̋͋̓̂͌̐̀̀́͗̄̃͐͊́́͗̀́̃͋͂̂̈̂̆́͑̚͘̚͘̚̕̕̕̚͘͜͜͜͠͝͠͝͝͠͝͠͝͠͝ͅͅͅ ̷̡̨̧̨̨̡̨̡̧̢̡̛̛̛͕̰̟̝̹̣̝͔͓͓̼̪̤̞̻̥̣̫̝̤̟͈̭̻͖̭̝͖̘̼̬͓͔̹̝͕̤̲̳͙̠̖̣̪̱͍̠͉̱̝͉̪͎̜̻̥̻̞͖̗̻͕̙͍̦̪͖̫̮̠̦̰̻̝̲͇̠̻̦̻̝̪̮̲̩̦͚͖̦̯͍͕͕̥̘͓͙̹̞̮̘͇̼̻̳̗͎̺́̓͆͊̂͗̎̅̓̂́͊̌̎̿̌͐̎̀͋̉̄̆̆̌̋͐͂̎̇͌̓́̋͛̾̇́̆̉́͌͐̉̀͘̕̚̚̕͘͜͜͜͜͜͝͠͝ͅͅͅͅͅͅą̷̢̢̢̧̨̡̨̨̧̢̨̢̨̧̛̛̛̛̛̙̼͕̭̬̳̲̪̯̠͙̖͇̟̝̼̞͕̦̫̬̣̣̣͈̠͖̤̪̩̬͍͖̩̰̼͔͇̰̜̤̘̤̩̱̰͓̘͓̥͔͔̱̤̬̦̖͕̰͎͎̪̦͎͎̙͇͕̙͎̹͇͍͇̦̦͉͚̗̤̼̣͚̱͔͍̼͖͔̫̣̗̰̗̖̳͔̫͖̦͉̥͕̘͙̼̰̫̜͕̳̫̭̙̱̼̰̻̟̫̮͎͇̤͈͓̗̲͎͍̤̯͎̟͕͔̹̳̞̗̼͓͐́͛̽̓̊̔́̿̿͑̓̉̅̆͆̊̈͑́͒̇̀͂̂̽̃͋̎͌̌̓̑̂͋̔̋̀̇͂̀͗̈́̈̋̿̔̀̉̽̍͂͆̉͋̀̐̂͑̆̓̇̎̓̉̎̆̈́̽̔̽̽͌̈̒͒̀̂͂͒̓͋̋̃̆͗́̈́͛̄͑̉̂̀́͌̓̽̐̀̄͂̌́̌̅̃͌͐̉͌̂̋̑̏̄̏̅͒̍͊̀̆̀̀̍̔́͆̏̑̒̊̌̉͒̾̽͂̽̐͂̈̔͛͌̓̄̿̈͊̎̀̚̚͘̕͘̚͘͘͘͘̚̕͜͜͜͠͝͠͠͠͝͠͠͝ͅͅͅͅs̷̡̨̧̨̢̢̨̛̛̻̝̮̣̱̱͚̲̙͇̠̙͕̼̰̬̪̲͚̥̦̮̻̲̣̭̥̝̰̘̹̲͕̯͔͙͎͍͚̤̤̦͎̗͙̫̲̦̥͙͖̼͈̻̱͎̘̼̪̤͔̯̫̈́͒̒̎̑͌̉́͋͒̃̾́̈͊̈́̂̈̊̀́̏̐̀̐͗͗̂̈́̀̈́̏͒̋̓̿̔͌̒̋́̅̆̑̂̿̋̈́̓̈́̍́̇̿̀̾̓͑̐͂͒̎̑̀͗͂̏̎̆̀̓̓̋̽͋̓͊͋̎̾̊͛̍̌̅́͂́̎̊̌̐̃̃͐̊͘̚͘̚͘̚̚͜͜͝͠͝͝͠͝͠ͅͅͅͅͅ ̴̧̨̡̧̡̢̢̧̧̡̨̨̡̡̡̨̡̢̡̛̛̛̛̛͎̦͎̲͙̙͓̦͉̜̮̫̖̖̯͎̜͚̳̪͕̜̼̝͕̖̣̥̼͍͔͚̩̠͎̼̻̠͚̦̯̦̙̝͇̞̦̙̞̙͔̳͚̝̦̘̰̻̟͔̳͚̝̹̺̪̦͓̘̼̮̭̣͇̫͇̩͉̝̺̪̜͉̯̘͍̬͈̳̦͉̘̝̺͈̖̰̖̥̳̰͇̭̟͍͉͉͉̜̜͍͙͙̥͇͕͎̖̖̪̘̮͕̦̦͍̺͉̟̞̟͕͖̝̪̠͙͉̺͔̳̻͎̫͐̂͌̿͌̿͑̐͐͊̅̒͊̏͛̓̋̿͒̑̍̋͗̂̇̂́̊́͆̄͋͊͑̏͗̍͐̒͋̾̌̑͒̀̿̀̃͐͌̂̊́͌̐̔̐͌̊̂̏̃̀́̑̿̈́͑̔͑̀̄̏̀͌͋͛̓̈́̈́̆̆̽̇̿̆́̈́̀̃̑͛͋̅̊̃̅̊̽͑̈̃̋̆͌͐̑̾̀̇͊̌́́̀̄̒̈́̐̀͂́̋̎͛̾̂̽̆̅͆̐́̒̃̄̈́̎̂̿́͗̃̒̔́̽̾͋̀̊͂͗͆̋̇̀̔̿̎̓̀̿̇̅̎́͗̈́͆́̒̅̍̓͗̈́̌̀̈́͗͑̏͗͑͆͐͊̈́̇̓̆̒͆̆͌͐̊͂̐̓̋̈́̀͛̏͒͌̃̔̇͑͒̋́̊̊̆̄͘̕̕̕̚̕̕̕͘̕̚͘̕̚̕̚͘͜͜͜͝͝͝͝͠͝͝͝͝͠͝͝͝ͅͅͅb̷̧̢̡̧̢̢̢̨̧̨̧̧̢̨̡̢̡̨̢̨̨̢̨̡̢̧̛̛̮͓̞̼̯̹̳͎͍̬̤̠̘̲̺̬͔̥̗̻͓̪̳͓͙̠͙͔̗̟̩̯̹̟̯̙̟͎̭̦͈̰̹̫̥͇͚̪͉̠̹͚̲͎͈̠̯̰̱̥̥̠̺̺̰̦͙͎̭̹̼͇̜̬͓̣͎̱̘̝̳̥͓̤͕̯̙͙̣̦̜̹̫̬̮͚͚̫̙͕̞̙͓͇̠̩͎͎̤̘͈̬̖̯̯̥̗̯͈͇͈̙͓͕̝̪̯̮̲͎͉̝̯͈̟̙̙̱̮̼̦̳̠̹͙̦̦̬͕̠̦̖̘̞̲̰̻͇̳͓͓̗̳̙̮̣̻͎̱̼̫̹͙̮̳̲̭̟͔̲͔̭̯͙̩̠̭̠̤̼͔̣̮͈̬͕̫̪̭̩̫̪͓̩͓̱̩̤͓̭̭͖̫̩̭̓̌̆́̓͑̊̍̃͋̈̑͛̆̋͗͗̌̌͛̀́̈̐̇̈́̀̈́̀̐͊̀͛̃̋͆̓́́̈̉̈́̉̈́͂̆̂͒̅̀͊́̉̾̈́̿̊͆͊̇͋̓͗͒̊͂̓̓̈́̀́̇͊͗̅́̈́̿͂͋̀̈͒͒̌͒̐̒̊̋̋̀̌́͑͂͗̔̒̌͗͗̎͒̽̍̄̂͆͑̑̓̋̊͆̑̂̃̄͐̀͆̐͛̀̋̿̈̀͘̚̚̚̕͘͘̕͘̚̚͜͜͜͜͜͜͜͝͝͠͝͠͠͝͠͠ͅͅͅͅȩ̶̡̨̢̨̧̢̨̧̨̧̧̡̡̢̧̡̢̨͉͇̝̺̘̬̪̱̙͉̲͎̣̞͖̩̠̱̲̞͔̜̝̝͙̞̫̬̯̘̮̤̻͎͓̺̦͔̝̙̤̟̟̤̬̫͈̹̩̠͕͉͉̱̲̫͉̪͈̝͓̬̭͚͇̰̖͈̥̞̺̗͎̦̜̭̼͎͈̹̯̣͇̤͈̰͍͙̭̠̫͚̺͈͍̦̪͙͓̩͉̠͚͖̬͇͖̟͉̣̤̥̳̦͉̺͕̱̖̩̦̦̜͖͓͈͓̳̣̖͚̼̘̮̯̞̺̦̱͇̫̫͕̣̙͓̳̠̭̻͍̪̟͚͔̠͕̳̥̖̝͍͓̻͈̝̩͓͈̤̦͈͚̹̲̳̭͕̦̰̙͂̏̆̄̉̂̀̇̚͜͜͜͝͝ͅͅͅͅͅͅͅâ̸̡̡̢̨̨̢̡̡̢̢̨̢̨̧̡̨̡̢̡̧̨̡̨̨̨̧̧̨̨̛̛̛͓͉̼̟̙̘̺̲̣̰̱͉̫̙̼̟͍͖͙̹̫̱̣̘̞͇̲͓͇͇̰̰͍̟̝̣̟̮͓̣̟̞̥͇͎̲̳̮̰̟͇͕̜͓̥͚̩͈̪̝͓̪̰͖̻͍̝̝̖̰͖̘̰̱̣̠͖͙̫̫̜͔͉̫̝͙̞̪̺̜̤̖̠̮͉̱͎̤̭̺̞̞̖͚̰͕̼͖̰̫̞̞̻̟͙͙̼͓̳̺̰̩͍͓̞͔̮͖̥̮̥̘̙̺̩̻̪̞̳̲͎̜̲̟̗̣͚͎̺̝̼͈̮̻̳̭̣̙̲̤̪̻̲͙͍͔͙̙̳̽͗͛̌͋̃̐͆͋̆͒̒̓̅̋̅̿̉̋̔̒̇͊̐̽͗̍͐̀̈́́̿̓͊̅̏̓̉̓̉͒̐͒̉͛͊̇͘͘̕̕͘̚͜͜͜͜͜͜͜͠͝͝͝ͅͅͅͅư̵̧̡̛̟̗̩̼͍̝̝̘̻͉̜̤̖̲̠̣̮̰̻̩̦̬͆͛̊̈́̃͐͐͆̃́̏͊̃̈́͋̔̏̌́̊͑̔͗́̌̈̽́̾͊̋̓͋̀̏̓͋̇̒̈̑͐͊̏̾̃̃̈́͒̊͐͊͊̆͊͂́̓̅́̊̄̊͒͛̓̑̈̽͛̆̆̃̇̒̒̎̅̓̃̓͋̉͐́͐̈́͊́̎͛̔̏͌̔̓̂̈́̓͛͋̈͂̍̅̃̈͒̋̓͂̓̆̔̀̐̔̆̌̏͋͆̿̀̊̀͛̌̾́̽̓͒̊͒͌͆͌̽̓̋̈́̿̌͊̾̑̊̾́́̎̐̿̈̊̊̀͒͋̐͑̽̍̈́̇͘̚͘͘̚̚̚͘̚̚͘̕͘͜͠͝͝͝͠͝͠͝͠͝͝͝t̶̢̨̧̢̨̢̡̛̛̛͈̪̥͕̹̫͙̖͖̙̼̲͓͓̳̟̺̠͇̞͕̮̘̳̜͖̳̮͍̤͇̝̻̱͇̟̜͕̮̺̩͖͔̱͎͇͙̬͕̙͓̤̭̞̮̩̤͙̖͉̹͎̳̳̯͖͎̯̦͔̤̟̝̗̖͍͓̖̫̲͖̗̮̮͈̼͙̰̼͓̥̲̻͔̬̼́̽̓͗͌͗̏̀̅̓̈́̓̓̽̏̌̆̈́̅́̋̀́̓̌̀̃̅̽̒̓͒̈̑̀̃̾̇͊͑͗̔̆͆̆͑̅̑̆̈́̓͑̓̽́̈́̓̔̉̔̆̓̀̔̈̍̎͗̓̓͌͊̃̍̃̄̋͐͛̅͋͊̓͌̈́̌̔̿̓͆̿͊̊̅͋͂̔̓͌̚̚͘͜͜͜͝͠͝͝͝ͅį̴̢̧̨̡̢̡̨̢̨̧̨̨̢̡̧̡̧̨̮̬̯̝̱̫̫̟̜͚͈̤̳͕͈̺͉̰̯̲͈̝̘͎͈̘͎̤̮̪̝̦͕͔̘͓̥̞̼͇͎͖̳̞͓̥̞̙̖̝͉͕̲̼̹̥̘͙̠̜͇͇̩͉̻̭̯̮̗͉̭͚̮̼̞̹̯̯̻̪͕̤̩̠̮̳͉̟̦̰̠͖̲̹̹̹̠͚̤̤̼͈̳͙̠̠̬̗̹̺͉̝̯͕͇̯͈̬̭̗͎̘̰̬͖̗̮̫̦̞̮͍̭̦̫͚͕̲̼͔̣̳̫̱̺͎͖͈̝̖̫͉̬̟̞̻̭̠͈̞̖͓̣͎̙͖͓͈͉͇̹̼̲͖̦͙̦̯͛͜͜ͅͅͅͅͅͅͅͅͅͅͅf̷̨̡̧̡̨̨̢̨̢̡̡̢̢̡̡̨̧̡̡̧̧͖̮̝̝̬̥̹̖͙͎̲̮̟̫͇̭̟̤̤͇̩̮͍͚̝̻̭͚̥̲̘̤͔̪̳͖̰̝͇̫̰̝͎̱͔͙̦̜̬̦̪͇̖͙̟̺̼͍̯̲̭̗͍͖͕͖̞̩͕̼̝̣͚̣͚̫̮̗̩͍̼̘̼̟͓̞̪͕͎̭̼͚̥̭̟̤̰̟̫͖̘͉͙͙̼̪̪̜̞̬̯̣̬͎̮̖͈̜͖̦̗͔̥̬̦̖̗͍͙̱͕̥͍̞̦͓̼͉͎̟̯͇̤͍̟͉̣̠̥̞̰̻̹͍̤͌̀̏̃̈́͌͛̈́͛͜͜͜͜͜͝ͅͅͅͅų̴̧̛̛͍͇̩̟͓͇̮͉̙͎̏̐̍̇̇̌̈́͑̓̏͆̆̐̃̍̊̎̈́͛̀͐́̔̄͌̑͗̒̌̋̎͗̎͋͌͆͆̐̋̄̐̾͐̿̿̍̍̉̎͂̄͑̈́̈́͂̀͗̎̈́̽̋̆̆͂́͌̔̾̌̚̚̕̚͘͘͘͘̚͠͝͠l̶̨̢̨̡̢̡̡̢̛̛̛̘̭̬̫̜̗̠̭̣̫̞̤͈͕̭͍̗͍̗̗͖̝̳͔͓̞͖̞̥̳̻̺͚̱̹͈̤͕̙̠̘̮͖̹̝̱̥̫̙̪̜̗̥̟̜̝̦̦͇̞͉̹̲̳̯͕̬͍̜͔͎͚̗̟̝͔̦͖̺̖̣̳̱̫̯̣̬̥̟̱̜̝̼̎̒̽̇̊͌̀̄̀͌̈́̋̓̎͋̏̄͌̀̿̃̐͊̿̐̀͗̐͛̅͒̃̈̈́̃͗͋̔̆̈́̽̓͊̅̾͑̂̄́̽́̐͌̃̀̿̄̽͆͋̐̊̾̌̃̈̀̓̔͂͌̑̑̀̅̂̓͒̎̄̅̽̋̿̇̆̽̽̽̀̆͂̓̒̿͆́̈͋͛͊͋̓̈́̎̌̀̽͋͋̎͒̏̍͗͑̔͊͐̋́̒̃̅̋̄́̆̾̔̈́̃̈͒̉͘̕͘̚̚̚͘͜͝͝͠͠͝͠͝͝͝͠͠ͅͅ ̴̨̧̡̡̧̢̢̧̢̢̧̛̛̛̲̝͍̠̳̗̬̦̯̘̺̯̙̞̩̪̖̮̫͙̟̦̻̙̬̫̮̩͍̳̬͙̟̫̭̭͇̖̤̗̣̜͍̩̥͕̭̤̮̫̫̣̭̗̣̠͈̲̣̠̻̣̺̻͎̠̩͚͇͍͎̯̰̠̫͖̗̫̣̜̜̱̬͙̝̫̥̙̖͚̼̥̥̯̗̗͈͎͉͉̟͉͕͍̬̮͇͍͙̟̰̥̥̬͎͓̬̫̗̤͉͍̦̞̩̭̲̭̭̹̱͙͉͖̙͖̓̄̅͋̅́̋̈̑̈́̅̃̂̓̃̀̇̅͂͑̋̈́͑͊̿̆̀̈̑̎̈́̈̔̂͌́̄̀̐̾̇͌͂͐̆̐̏̍͐͛́͑̃̈́̾̌̚̚͘͘͜͠͠͠͝͝͠ͅà̶̢̢̧̡̛̛̛̺̟̯͕̠͙͖̘͉̱̞̥̰̹̪͚̰̥̲̯̤̘̪̥̱̫̫̬̦͕̮̤͓̦̹̫͇͎̦̼̘̞̥̫̼̥͈͓̗̲̙̼͚͉̻̫̠̞̩͍͔͓̝͓̎͛̃͐͗̍̀́̌͗̈́̓͗̿̀̓̉͐́́̅̓̾̿̉̊̈̄͂́̽͆̆̌̊̊͛̏̎̀͂̓̈́͑̌̓̾͒͌͛̍̽̈́͌͆̀̏̀͂̏̊̈́̉͆̑̒͋̊̈́́͒̆͌̓̋̃̒̃͌̀́̈́̄͛͐̄̏̔̂̿̿͒̇̒̇̌̋̈͑͒͒͐̓̓̌͒̀̽̌͑͒́̉̒̌̿͛̊̇̉̓̀̓̅̔̂̄͋̈̆́̀̐̄͂͊̾̏̈̉̄̏̒̑͌͂̚̚͘̕͘̕̚̕̚͘̚͘͘͘͝͝͠͝͝͝͝͝͝͝͝͠͝͠ͅs̵̨̡̧̨̡̨̡̛̛̛̛̛͙̙͍̯͉̪̬̖͖̞̯̞͈̥͓̥̩̙̘̰̰͙̬̠̯͈̭̹͎̹̳̞̗̫̺̫̦͉͈͎͔̳̗͔̝͔̬̲̰͇̯̳̫̜̠͚̞̮̳͚̼̳͓͎̹̳̙͓͔̟̠̮͔̘͇̬̟̣͍͈͍͙͚̟̦̦̱̼͔̜̜̭̣͍͚̱̯̄͊̅͆͐́͒̅̋̋̍̾̎̓̇̀͗̋̓̀̑̑̇́̾̃͆̂̓̿̈́͆̉̀̃͊͌̄͗͐̅͐͗̉͌̑̾̉̑̃̐̓̌̌͐̉̓̌̅͐̑͂̔͛̃̃͌̑̽̂̄̅̀̄́̇̆̊͛͑͂͂̈́́̉̓̍̿̅̒̃̀̾̏̾́̽̅̊̇̈͐̊̒̐̎̈́͐͂̔̽̾͐́̈́̏̈́̑̈̅̊̚̚̕̚̕͘͘̚̕̚͜͜͜͠͝͝ͅͅͅͅ ̷̢̡̧̨̢̢̨̧̨̨̧̡̛̛̛̛̲̥̯̞̩̪̤̹̹̼̳̭̥̬̹͚̟̖͕͚̳͔̭͙̞̰͚͇̮͚̞̖̳̮̠̼͓̺̞̝̺̘̰͓͎̹̤̬͚̲̠̹̪̞̗͎̥̭͈̹̝͕͙̞̝̥̰̟̭̬̠̻̰͉͕͖͙̝͓̟̜̯̤̜̼͓̘̮͇̦̳͖̬̻̬͓̗̘̱̮͉̜͚͍̭̰͖̘̬̞̳͙̗͓̬̮̝̠̞̪̺͎̪̳̬̮̼̩̞̠̝̮̯͕̗̙̦͖̠͉̮̯̫͓̤̭̯͓͖͙͍̹̫̠̩̯̩̫̬̩̗̤̯̠̖͇̜̲̲̙̻̘͑͊̽̈́̿̄͒̋̌̎̃̃̈́́͒̍̏̄̾̃̀͑̽͛̐̃̃̈́̒́̈̒̀̔̌́̌̽̍́̑̑̌̔̅̽̑́̑̐̆̈͑̄̓̀͋̍̏̋̄͐̀̈́͑͌̀̒͐̇̓͆̎͌̿̏̾̈́̈́̿̅͊̀͑͂̃͆̾̔͐̅̄̋͆̔̾̆̌͒̓̿́͋͛̓͐̔̔̏̏̌̑̆͂̆̄̍̍̇͒̃̌̑̈́́̈́̄̂̐̽̉̋̇̏̋̋̈́̈́̈̐̍̽̇̂̋̒̔̏̌̅͂̒̓͒̃̆́̏̄̌̈́͗̉̔̊̄̌͊̂͗̈́͊̐̉̓̽͌̈́̐̑̇͌̓̈́̐̄̇͗͒͆̎́̈́̓́͗̈́́̄͑́̇̍͑̎͗̀̕̕̕̚̕̕̕̕̕̕̕̚͘̕̚͘̚̕͜͜͜͝͠͝͝͠͝͝͠͝͠͝͝͝͝͠ͅͅͅͅͅͅͅͅͅa̶̡̨̡̛̛̛̛̛̛̛̪͓̳̝̭̭̲̟͙̜͚̬̰͖͓̰͍͈̪̻̤̬͇̹̬̞̣̫͓̳̻̣͖̩̯͔͈̥͖̯̖͚͕̞͙͍̟̟͇̖͙̞̐͗̉̏͗̆͌̇̈́̄̂̍̔̈́͊͑͂́̓̉̉͛̽́̈̄̎̈́́̃̅̈́͐̾͛̑̃̅͑̅̄̍̒̀͂̆̾̐͗̋͛̓̀̏̇͐̿̆̈́̊͌̓̈́̊̄̀̄̾͂͌̒̎̂̇̔̍́̋̆̃̏̅̓͌̒̈́̆̑̋̑̍̆̏̅̓̀̏̏̃̈́̿̽̓̿̒̑̒́̉̆͑̏̋́͌̍̏̈́̓̿̓̾͐̎̔̒̓̔̒̽̋̿͐̎͒͛͂̾̅̈́̾̊̀͊͗͐͌̀͑̋͆͌̂͗̐͋̂͐̽̈̐́̄͋͋́̀̎͊̃̓͗̔̈̅̈́̑͊̀̏͂̈́̔̓̋͌̈́̿͂̈́̏͛̀͌̈́͑̒͑̂̃͐̈́̈́̅͋̽̓̋̑́͆̽̌̅̋̑̏̈̾̅̎͒́́̓̆́̍̀̍̆̍̍̿̌͐͊̒͛̌̓͂̐͊̃̈̆̚̕͘͘͘͘͘͘̕̕̕̕͘͘̚̕̕̚̕͘͜͝͠͝͝͝͝͝͝͝͠͝͠͝͠͝͝͝͝͝͝ͅͅͅͅͅ ̴̡̢̨̡̧̢̧̡̧̡̨̢̢̧̨̨̢̨̡̧̡̡̨̡̨̧̨̢̡̢̢̧̨̛̛̛̛̛̱̦̩͇̻̼͓̻̼̝̖̙̩̦̞̜̘̭̘̮͉̮͉̘̦̭̞̰̪͚͔̪̼͕̞̬̫̣̳͖̥͎̺̹̙̝̝̳̭͙͙̮̺̣̜͕̘̰̥̘͍͓̮̞̤͓̞̳̬̼̤̝̲̙͖͍͕̯͎̺̮̜̩͙̲͔̦̬̱̼̪͓̹̳̥͉̰͕̣̪̹͉͚̥͚̘͙̠͓̻̞̟̻͈̜͚͖͖̭̗̘͕͚͕̠͖͓̞̠̜͔̜̟͖̥̼̤̱̭̟̼̥̠̹̥̪̮̗̹͍̺̰͖̮̳̰͍͉͍̖̙̙̺̻̦͖͖̭̗̘̺̻͈͙̜̠̬̻̘̬̬̼̻̜̰͕̜̳͎̥͕̼̟̯̟̘̼̞̺͎̳̬̹͈̜̬̘̖͎͉̺̲̠̜͖̟̞̟̳̳͙̤̪̬͔͎̲̯͔̜̣̥̼̐̄̔̅̀͂̾̐̍̽̓́͒́̍̈͒̔̂̆̐́̒̃́̈͗͒̂̽́͑̎͒̈̊̐͛̊̀̄͒͐̓͑̍̉̎͂̂͂͊̀͊̃͂̏̋̉̿̅̎̀̏̉͌́͛̓͑̉̃͊͗̉͗̋̕͘̕͘̚͘͘̕̚͜͜͜͜͜͜͜͝͝͝͝͝͝͝ͅͅͅͅͅͅͅͅͅş̵̛̛̛̛̛̛̱̗̬͈͇̥̦͓̩̥̀͒̂̅̓̍̉̒̾̈́́͂͑̊̊͗͋̆̍̍͗̉̂͆̏̈́̇͆͋͆͂͒́̈̈͑̑̀̋́͐̌̌́̀̈́̒̅̌̇̅͛͌̌̀̾̓̆̈́̈́̈́͗̈́̃̃͛͛̅̅̂̓̽̇̂̽́́̄̉̀́̋̋͂̇̅̓́̽̾̆̓͑́̀̀̓̓̏͛͂̉͗̑͒̄̽̄̐͐̔̇̔̎̓̅̆͌̓̈́́͛̆̃̉̈́̓̄̅̈͆͂̉̑́̒̇̆̅̆͋͑͘͘̕̕͘̚̚̕͘̕̚͘̚͝͝͝͝͠͝͝͝͝͝h̶̢̧̢̨̨̡̧̧̧̨̧̡̨̨̧̨̡̛̛̛̛̛̛̯͈͎̬̞̯̦͇͈͍̟̟͓̜͓̫̜̮̮͍̼̲̦̞̜̖͉͍͈̦̥͎̙̟̭̬͉̗̱̙͕̱̗̖̺̥̪̤̼̦̞̘̻͍̤̖̞͎̫͖̹̥͙͇̥̣̣̜͎̩̮͓̜̟̪̜͇̝̮̰̮̜̖̝̳̦͙̳̫̯̪̜͈̘͉̳̪̬̦̫̗̣͕̟̲͔̯͚̺̳̮͈̬̘̠̻͇͙̰̻̩͖̙͉̣͍̗̦̳̲͈̗̜̺̭̫̰̜̣̩́͗̊͂͛̈́̐́͛̑̓̓̈̍͑́̅̉̈́̿̐̓̎̀̾̋́́̉̑̎̀̔̀́͊̑̽̆̊͌̈̈́͛͗͋͛̄͌̓̅̒͆̀͌̍̑̐́̌̔̎̌̐̆͋̅̎̾̄̌͋̾̆͆̈̒̈́̐͐̄̐̀̿̇͗̓͐́̾̇̓̈͐͋͆̎̓̓̎͑̌͊̓͆͂͑͋̾͑̾̓̀̀̔͛͑́͒̋͑̀̌̈̾̑̓͑̈́̑͐̍̎̉̒̒͗̈́̑̈͂̎̓̒̾͌̌̆̔͆̇̅̈́̎͛̈́͂́͋̆̑̓́͗̃̋̆̽̽̒̀͂̏͗̆͛́̂͊̓̇̎̀̎̓̓̿͂͌̌͑̏̐̚̚̕͘̕͘͘͘͘̕̕̚͘̕͜͜͜͜͝͝͝͝͝͠͝͠͝͠͝͝͝͝͝͠͝͠͝͝͝͝ͅͅͅͅͅȩ̷̢̧̡̛̛̛̳̗̳̝̝̺͎̪͔̟̝̖̫͎̞͕̰̖̩̞͙̻̞̱̻͙̹̪͉͖͍̗̩̪͓̦͖͎̝͉̲͚͖͙̗͍̱͔͓̹͕̦͕̬̖̖͚̳͉̲̰̳̳͍͙̠̪͈̖͋̀͋̊̓̍̇̅̑͊̀̈́̈́̋͂̃̿́͌̓̒̔̊̇̀̅͒̓͌͛́̇͌̽̾̒̏̈́̓͂́̏͌̉͗̇̇̄̇̑̈́͋̐͂̋̄̂̀̓͐̂̾̍̀͌̆́̽́̈́́̈́͌̽̊̄̈̏́̾͌̈́͂͊̇̍̿̈́͐͂̑̀̈́̉̈́͑́̅̐̀̔̉̐͌̓͐̂̌͒̍͆̽̍̊̈̂̕̕͘̚̚̚͘͘͘͜͜͠͝͠͝͝͠͠ͅͅl̴̢̡̢̢̧̧̧̛̲͉̙̦̜̘̖͉̭̙͕̹̻͙̮̹̩̭͙̫̟͖̩̝̮̜̗̪̙̹̘̮̰̼͓̭̮̲̼͕͇̖̱͕̳̖̥̰͙̖͉̣̣̙̙̱͓̣͎̖͚̠̞̣̹̰͍̱̭͔͖͎̜̣̙̜̮̼̹̻͈̹͉̟̖̉̈̈̒̐̆̍̌̅̈́̈͆̎̈́́̑͒̄̎̒̂̾͌̆̀̅́̓͆̇͊̈́͆͑̄̀͆̉͆͑̿͊͗̑͑̃̔͑̌̀̀͛̂͐̋̓̓̊̈́̈́͑͋͐̇͛̒̾̂͋͑̈́̋̑̚̚̕̕̕͜͜͝͝͠l̶̡̡̨̡̢̢̨̡̡̨̻̥͔̼̟̰̖̲̭̝̣͙͎̻̙̱̰̱͚͎̪̙̻̮̣͉͓̹̩̫͕͓̰̪̭͕̩̺̼̪̼̥̟̜̗̝̳̘̼̯͖̱̩͍̭̙̙̭̭̱͎̙̺̞̯͎̮̤̼̯͇̠̯̗̟̜͈̻̮̤̗̝̪͉͙̖͈͍̭͉̮͍̠̖̣̮̞͇̰̒̔̌̑́̑̌̾́̐̀̍̄̅̇̃̀̎̓͛́̏̐͑̐̅̅́̿͆̿̉͋̅͌̿̃̄͛̾̎̂́͗̚̚̚͘͜͜͜͠ͅͅ ̷̡̢̡̨̡̧̧̨̢̡̧̨̨̢̢̢̧̡̢̡̨̛̜̫͖̺̞̥̩̣̮͈͉̝̩̟̻̰͔͓̳̫͇̭̯̰̬̩̹̥͓̠̹̳͍̝͙͓̻͔̼͎͚̲̻̲̯̫͉̗̩̪̼͈͓̲͉̙͍̬̩͈͓̱̞̬̮͓̻̟͈̠͉̠̟̻͈̰͕͖̜͈̣̰̩̦͚̹̪̹̘̱͙͇̘̺̼͉̪̹̫̲̫͍̲͍͇̣̦̠̝̗̦̗͇̗̲͇̗̞͉̯̯̗̟̫̖̞̖̺̺̺̘̘̞̯̮͖͓͕̺̺̞̠̮̹̳̘̼̹̼͎̜̟̘̖͙̭̝̮̦̺̩͙̦̭̘̱̘̹̗͕͈̮̟̪͔͚̺̰̱̟̘̰̤̟͉̘̯̪͙̼̦̗̮͓̬͚̘͈̻̖̙͖̩͖̺̫̼̃͑̈́̒̀̍̂̋̓̒̿̽̀̃͌̾́̓́̉̀̄̔̏̄̕͜͜͜͜͜͝͝͠͝ͅͅͅͅͅͅͅͅT̷̨̨̧̡̢̧̧̛̛̛̛̛̰̟̝̻̰̖̼̰̞͓̱̤͚͎͉̮̟̗̞̤̳̮̫̻͕̦̩̤̲̤̩̻̯̙̻̠͍̟̗̬̪̥̩̦͔͚͔̫͉̘̖͍͔̞͓̪͖̤̺͍̟̯̫͇̹̗̹̫̮̬͚̠̝̹͇̥͙̮̫͓̮̜̈͑̾́͂͌̎̏̓̃́̌̓̒̂̃͛̍̽̆̑̆̾̒̓͐̋̃̿̀̊͂́̀̊͛͊͊̈̊̉̎̄͌̄̌̑́̓̈́̊͋̆͐̈̉͗̈́̀̏̀̄̽̐̄̄͑̿͊̃̏̅́̉̌̀̀̄̋̊̅̈́̒̉͗͋͋̽̽̂̎̌͑̋͆̾̔͒̉̿̆̌̽̽̈́̈̍͆͗́̈̿̂̓͂̑̀͐̑͛̄̋̌͋̅̓̆̿̿̇̂̊̉͆̒͂̏̂̏̓̏́́̉̎̊́́́͗̊̓͛̊͒̾́̆̈́̃́̈̔̅͛̓́̀̋̋̈̔͛͊̿̉́̇́̑͂̂̉́͑͂̈́̏͐͆͊̋͒̊̈́̌͑̍̒̋́̒̕͘̕̕͘̚̚̚̕̚͜͜͜͜͜͝͠͝͝͝͠͠͠͝͠͝͠.̶̨̛̛͚̳͈̪̹͔̤̱̂̏̅͌̒̿̓̈́̍͆͋̓̎̂̊͋̂̑̌͗̍͊͌̾͐̋̉̉̇̊̿͌̚͘̚͝͠T̷̡̡̨̡̨̡̨̢̛̲̳̞͖͈͍͎̮̳͈͍̦̭̣̯̬̣̰̲̬͓̘̱͓̳̞͙͇̭͇̳̪̩̭̬̘̭̲̜̺͖͖͙̲̰̟̞̳͔̙̞͓̱͓̜̪͎̙͎̪͖̼͚̯̩̹̺̭̗͉̮͓͔͉͚̿̔̍͆̽́̄̿̍̓̊̎̈͊͌̎̈̈́̔͗̿͋͑̄̄̃́̓̒̋̍̐̏̽̎́̈́̀̏̓̚̚͝ͅͅͅ|̵̧̨̧̢̨̡̧̢̧̢̢̧̡̢̨̢̧̧̡̢̡̧͖̫͈̹̗̺̖̠̝̱̫͎̙͓̫̻̗͍̠̜̱̯̫̺̹̬̰͇̻̖̹̜̹͉̥͎̱̥̫͍̞͈͈̙̭͓̘̦͇͙̭͚̱̙̳̹͇͓̩͕̗̘̪̭͇͈̖̜͚͍̹̘͇̼̻̲̥̭͔͕̰̹̼͍̻̣̟̰͉̖̣͙̭͚͙̞̜̥̘͉͕̩͇̺͔͙̩͔̣̯̭̤̤̳̗͔͔̫̖͕̺̲̱̙̠͙̺̗̖̣͉̣̮͎̣͚̭͇͖͙͖̻̳̼̪͖̬̻̲̻̼̪͇̲̭̹͔̭͍͙̣͔͉̱̼̤̱̻̲͎̪͕͇̼̇̽̀̉̅̈́̐̀̀̌̍͗̌̾̌̾́̽̑̑͒́̄̓̔̀͑̍̓͐̓̀͋͂͘̕̚̚̚͜͜͜͜͜͜ͅͅͅ\n");
	printf("\t\t    |Hopefully as beautiful as a shell T.T|\n");
	printf("\033[0m\n");
}

void	interpreter(char *input, t_main *main)
{
	if (syntax(input))
		return ;
	if (command_splitter(input, main))
		return ;
	if (tokenizer(&main->cmd_head))
		return ;
//	if (parse(main))
//		return ;
	printf("print:\n");
	print_cmd(&main->cmd_head->main_ref->cmd_head);
	printf("___________________\n");

}

int	main(int argc, char **argv, char **envp)
{
	int		exit = 0;
	char	*buff;
//	int i = 0;
	t_main	main;

	(void)argc;
	(void)argv;
	fancy_init();
	main.env_head = NULL;
	main.cmd_head = NULL;
	copy_env(&main.env_head, envp);
	signal(SIGINT, wt_sig);
	while (exit != 1)
	{
		buff = readline("Minishell> ");
		if (!buff)
			return (printf("Minishell> exit\n"));
		if (ft_strcmp(buff, "env") == 0)
			print_env(&main.env_head);
		add_history(buff);
		if (buff != NULL)
			interpreter(buff, &main);
		free(buff);
		clear_cmd_list(&main.cmd_head);
		clear_env(&main.env_head);
		return 0;
	}
	return (0);
}
