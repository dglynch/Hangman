/*
Title: Hangman
Programmer: Dan Lynch
Filename: hangman.cpp
Program Description: A computerized version of the traditional game Hangman
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <allegro.h>
#include "hangman.h" // contains #defines for datafile

DATAFILE* data; // variable to hold all data

////////////// Title Screen /////////////////

void title_screen()
{  set_palette(black_palette); // temporarily blank the screen
	blit(data[GAMEBACK_PIC].dat, screen, 0, 0, 0, 0, 640, 480); // wood background
   blit(data[FLICBACK_PIC].dat, screen, 0, 0, 150, 110, 340, 260); // cut out square in middle
	BITMAP* window = create_sub_bitmap(screen, 160, 120, 320, 240); // allows FLIC playing

   for (int c = 0; c < 7; c++) // draw the underscores
		textprintf_centre(window, data[BIG_FONT].dat, c * 20 + 100, 110, 255, "_");
   rest(2000);

   fade_in(data[GAMESCREEN_PAL].dat, 3); // slowly fade in
   text_mode(-1); // transparency mode
   for (int c = 0; c < 7; c++) // slowly fill in the word 'HANGMAN'
   {  textprintf_centre(window, data[BIG_FONT].dat, c * 20 + 100, 110, 255, "%c", "HANGMAN"[c]);
      if(keypressed()) continue; // do the rest quickly if they press a key
      play_sample(data[BANG_WAV].dat, 128, 128, 1000, 0); // bang
   	rest(1000);
   }
   rest(500);
   fade_out_range(64, 254, 254); // blank this colour
   textprintf_centre(window, font, 160, 200, 254, "Copyright (C) 1998 by Dan Lynch");
   fade_in_range(data[GAMESCREEN_PAL].dat, 3, 254, 254);
   rest(500);
  	fade_out_range(3, 254, 255); // fade out both whites

   do // this is a loop to allow 'break's
   {  if (keypressed()) break;
   	rest(200);
   	clear(window);
	   textprintf_centre(window, font, 160, 110, 255, "Design & Programming");
	   textprintf_centre(window, font, 160, 112, 255, "____________________");
	   textprintf_centre(window, font, 160, 130, 255, "Dan Lynch");
      if (keypressed()) break;
	   fade_in_range(data[GAMESCREEN_PAL].dat, 3, 255, 255);
      if (keypressed()) break;
	   rest(2000);
      if (keypressed()) break;
	   fade_out_range(3, 255, 255);
      if (keypressed()) break;
	   rest(200);

	   clear(window);
	   textprintf_centre(window, font, 160, 110, 255, "Wood Texture");
	   textprintf_centre(window, font, 160, 112, 255, "____________");
	   textprintf_centre(window, font, 160, 130, 255, "Steve King");
      if (keypressed()) break;
	   fade_in_range(data[GAMESCREEN_PAL].dat, 3, 255, 255);
      if (keypressed()) break;
	   rest(2000);
      if (keypressed()) break;
	   fade_out_range(3, 255, 255);
      if (keypressed()) break;
	   rest(200);

  	   clear(window);
	   textprintf_centre(window, font, 160, 90, 255, "Category Art");
	   textprintf_centre(window, font, 160, 92, 255, "____________");
	   textprintf_centre(window, font, 160, 110, 255, "Ontario Ministry of Tourism");
	   textprintf_centre(window, font, 160, 130, 255, "Microsoft Corporation");
	   textprintf_centre(window, font, 160, 150, 255, "Wizards of the Coast, Inc.");
      if (keypressed()) break;
	   fade_in_range(data[GAMESCREEN_PAL].dat, 3, 255, 255);
      if (keypressed()) break;
	   rest(2000);
      if (keypressed()) break;
	   fade_out_range(3, 255, 255);
      if (keypressed()) break;
	   rest(200);

  	   clear(window);
	   textprintf_centre(window, font, 160, 110, 255, "Sound Effects");
	   textprintf_centre(window, font, 160, 112, 255, "_____________");
	   textprintf_centre(window, font, 160, 130, 255, "LucasArts Entertainment Company");
      if (keypressed()) break;
	   fade_in_range(data[GAMESCREEN_PAL].dat, 3, 255, 255);
      if (keypressed()) break;
	   rest(2000);
      if (keypressed()) break;
	   fade_out_range(3, 255, 255);
      if (keypressed()) break;
	   rest(200);

  	   clear(window);
	   textprintf_centre(window, font, 160, 110, 255, "Game Library");
	   textprintf_centre(window, font, 160, 112, 255, "____________");
	   textprintf_centre(window, font, 160, 130, 255, "Allegro 3.0 -- Shawn Hargreaves");
      if (keypressed()) break;
	   fade_in_range(data[GAMESCREEN_PAL].dat, 3, 255, 255);
      if (keypressed()) break;
	   rest(2000);
      if (keypressed()) break;
	   fade_out_range(3, 255, 255);
      if (keypressed()) break;
	   rest(200);

   } while (0);
   fade_out(3);
   rest(200);
}

////////////// Menu Screen /////////////////

int menu_screen()
{	clear(screen);
	while (keypressed())	readkey(); // flush

   blit(data[GAMEBACK_PIC].dat, screen, 0, 0, 0, 0, 640, 480);

   // these lines draw the outlines
   blit(data[CATEGBACK_PIC].dat, screen, 0, 0, 158, 35, 150, 120);
   blit(data[CATEGBACK_PIC].dat, screen, 0, 0, 333, 35, 150, 120);
   blit(data[CATEGBACK_PIC].dat, screen, 0, 0, 70, 180, 150, 120);
   blit(data[CATEGBACK_PIC].dat, screen, 0, 0, 245, 180, 150, 120);
   blit(data[CATEGBACK_PIC].dat, screen, 0, 0, 420, 180, 150, 120);
   blit(data[CATEGBACK_PIC].dat, screen, 0, 0, 158, 325, 150, 120);
   blit(data[CATEGBACK_PIC].dat, screen, 0, 0, 333, 325, 150, 120);

   // these lines draw the pictures
   blit(data[CATEGORY1_PIC].dat, screen, 0, 0, 168, 45, 130, 100);
   blit(data[CATEGORY2_PIC].dat, screen, 0, 0, 343, 45, 130, 100);
   blit(data[CATEGORY3_PIC].dat, screen, 0, 0, 80, 190, 130, 100);
   blit(data[CATEGORY4_PIC].dat, screen, 0, 0, 255, 190, 130, 100);
   blit(data[CATEGORY5_PIC].dat, screen, 0, 0, 430, 190, 130, 100);

   // put in the text
   textout_centre(screen, font, "1. Cities", 233, 50, 255);
   textout_centre(screen, font, "2. Countries", 408, 80, 0);
   textout_centre(screen, font, "3. Islands", 145, 195, 255);
   textout_centre(screen, font, "4. Mountains", 320, 255, 255);
   textout_centre(screen, font, "5. Rivers", 495, 195, 255);
   textout_centre(screen, font, "6. Instructions", 233, 381, 255);
   textout_centre(screen, font, "7. Quit", 408, 381, 255);

   fade_in(data[GAMESCREEN_PAL].dat, 3);

   show_mouse (screen);
   char choice = -1;
   while (choice < 0 || choice > 6) // make sure valid input
   	if (keypressed())
			choice = readkey() - 49; // convert to int (1 becomes 0, etc)
      else if (mouse_b && mouse_x >= 158 && mouse_x <= 308 && mouse_y >= 35 && mouse_y <= 155)
      	choice = 0;
      else if (mouse_b && mouse_x >= 333 && mouse_x <= 483 && mouse_y >= 35 && mouse_y <= 155)
      	choice = 1;
      else if (mouse_b && mouse_x >= 70 && mouse_x <= 220 && mouse_y >= 180 && mouse_y <= 300)
      	choice = 2;
      else if (mouse_b && mouse_x >= 245 && mouse_x <= 395 && mouse_y >= 180 && mouse_y <= 300)
      	choice = 3;
      else if (mouse_b && mouse_x >= 420 && mouse_x <= 570 && mouse_y >= 180 && mouse_y <= 300)
      	choice = 4;
      else if (mouse_b && mouse_x >= 158 && mouse_x <= 308 && mouse_y >= 325 && mouse_y <= 445)
      	choice = 5;
      else if (mouse_b && mouse_x >= 333 && mouse_x <= 483 && mouse_y >= 325 && mouse_y <= 445)
      	choice = 6;

   show_mouse (NULL);
   fade_out(3);
   rest(200);
	return choice;
}

//////////////// Instrucutions ///////////////

void instruct_screen()
{
	set_palette(black_palette);
	blit(data[GAMEBACK_PIC].dat, screen, 0, 0, 0, 0, 640, 480); // wood background
   blit(data[FLICBACK_PIC].dat, screen, 0, 0, 150, 110, 340, 260); // cut out square in middle
	BITMAP* window = create_sub_bitmap(screen, 160, 120, 320, 240); // allows FLIC playing

	char instruct[700];
   int x = 0, y = 0;
	strcpy(instruct, data[INSTRUCT_TXT].dat); // put the instructions in a file
   for (int c = 0; c < strlen(instruct); c++, x++)
   	if (instruct[c] != '\n')
			textprintf(window, font, 8 * x, 10 * y, 255, "%c", instruct[c]);
      else // start a new line
      { 	y++;
         x = -1;
      }
   textprintf_centre(window, font, 160, 200, 255, "Press any key to return.");

   fade_in_range(data[GAMESCREEN_PAL].dat, 3, 0, 254); // bring in wood
   rest(200);
   fade_in_range(data[GAMESCREEN_PAL].dat, 3, 255, 255); // bring in text
   readkey();
   rest(200);
   fade_out(3);
   rest(200);
}

///////////////// Read in Word ////////////////

void get_word(char* fullword, int category)
{	char fulltext[256]; // holds all the words in the selected category
   strcpy(fulltext, data [WORDS1_TXT + category].dat);

   int word_num = rand() % 20; // chooses the word
   int start = 0; // where does the word start in fulltext?
   for (int newlines = 0; newlines != word_num; start++)
		if (fulltext[start] == '\n')
      	newlines += 1;

   int c; // counter for fulltext
   int d; // conter for fullword
   for (c = start, d = 0; fulltext[c] != '\n'; c++, d++)
   	fullword[d] = fulltext[c];
	fullword[d] = '\0'; // finish string
}

///////////////// Add a Part ////////////////

void addpart(int* dead, BITMAP* deadman)
{	*dead += 1;
   play_sample(data[ADDPART_WAV].dat, 128, 128, 1000, 0); // thoink
	switch (*dead)
   {
   	case 1: // head
      	fade_out_range(64, 254, 254); // fade out this white
      	circle(deadman, 80, 60, 20, 254);
         fade_in_range(data[GAMESCREEN_PAL].dat, 3, 254, 254); // fade it in
         break;
      case 2: // body
      	fade_out_range(64, 253, 253);
         line(deadman, 80, 80, 80, 190, 253);
         fade_in_range(data[GAMESCREEN_PAL].dat, 3, 253, 253);
         break;
      case 3: // (my) left arm
      	fade_out_range(64, 252, 252);
      	line(deadman, 80, 120, 40, 120, 252);
         fade_in_range(data[GAMESCREEN_PAL].dat, 3, 252, 252);
         break;
      case 4: // right arm
      	fade_out_range(64, 251, 251);
      	line(deadman, 80, 120, 120, 120, 251);
         fade_in_range(data[GAMESCREEN_PAL].dat, 3, 251, 251);
         break;
      case 5: // left leg
      	fade_out_range(64, 250, 250);
      	line(deadman, 80, 190, 40, 260, 250);
         fade_in_range(data[GAMESCREEN_PAL].dat, 3, 250, 250);
         break;
      case 6: // right leg
      	fade_out_range(64, 249, 249);
      	line(deadman, 80, 190, 120, 260, 249);
         fade_in_range(data[GAMESCREEN_PAL].dat, 3, 249, 249);
         break;
   }
}

///////////////// Game Play /////////////////

int game_play(int category)
{  // positons and sets-up the three sections of the screen
	BITMAP* deadman = create_sub_bitmap(screen, 40, 40, 160, 300);
   BITMAP* answer = create_sub_bitmap(screen, 240, 40, 360, 300);
   BITMAP* alphabet = create_sub_bitmap(screen, 40, 380, 560, 60);
   // draws the main game screen
	blit(data[GAMEBACK_PIC].dat, screen, 0, 0, 0, 0, 640, 480);
	blit(data[DEADBACK_PIC].dat, deadman, 0, 0, 0, 0, 160, 300);
	blit(data[ANSWERBACK_PIC].dat, answer, 0, 0, 0, 0, 360, 300);
	blit(data[ALPHABACK_PIC].dat, alphabet, 0, 0, 0, 0, 560, 60);

   textprintf_centre(answer, data[BIG_FONT].dat, 180, 20, 255, "Hangman");

	char fullword[16]; // holds the answer
   get_word(fullword, category); // gets the answer from the datafile

	int alpha[26]; // stores whether or not they have chosen a given letter
   for (int c = 0; c < 26; c++) // sets all letters to 'unchosen'
     	alpha[c] = -1;

   int letter[16]; // holds whether or not they've revealed this letter
   for (int c = 0; c < strlen(fullword); c++) // sets all letters to 'unrevealed'
      if (isalpha(fullword[c]))
      {  letter[c] = 0; // alphabetic characters are hidden
         // draws underscores beneath letters
        	textprintf_centre(answer, data[BIG_FONT].dat, c * 20 + (390 - strlen(fullword) * 20) / 2, 100, 255, "_");
      }
      else // non-alphabetic characters are revealed
      { 	letter[c] = -1;
	     	textprintf_centre(answer, data[BIG_FONT].dat, c * 20 + (390 - strlen(fullword) * 20) / 2, 100, 255, "%c", fullword[c]); // reveal the letter
      }

   fade_in(data[GAMESCREEN_PAL].dat, 3);
   text_mode(-1); // sets text output to transparent background mode

   int dead = 0; // how dead is the player?
   int win = -1; // 0 = lose, 1 = win, -1 = did not finish
   position_mouse(280, 30);

   while (1)
   { 	blit(data[ALPHABACK_PIC].dat, alphabet, 0, 0, 0, 0, 560, 60); // clear
	   for (int c = 0; c < 26; c++) // redraws the alphabet
      	if (alpha[c]) // if they haven't used it, write it
	   		textprintf_centre(alphabet, data[BIG_FONT].dat, c * 20 + 30, 15, 255, "%c", c + 65);

      int all_done = 0; // did the player win?
      set_mouse_range(0, 0, 550, 44); // limit their mouse
      show_mouse(alphabet);
      char key = 0;
      while (!key)
      	if (keypressed()) // read in from keyboard
	   		key = readkey();
      	else if (mouse_b && mouse_x >= 20 && mouse_x <= 540 && mouse_y >= 20 && mouse_y <= 40) // read in from mouse
				key = mouse_x / 20 + 96;
      show_mouse(NULL); // erase mouse
		set_mouse_range(0, 0, 639, 479);

      if (key == 27) // escape key
      	break;
      else if (isalpha(key)) // alphabetic key
      {  if (alpha[tolower(key) - 97]) // still available
      	{
	 	   	alpha[tolower(key) - 97] = 0; // set letter as having been guessed
	      	int is_there = 0; // assume the letter is not present
            all_done = -1; // assume the player has won
	        	for (int c = 0; c < strlen(fullword); c++) // check each letter
            {
					if (tolower(fullword[c]) == tolower(key))
      	      {	letter[c] = -1; // mark letter as revealed
		         	textprintf_centre(answer, data[BIG_FONT].dat, c * 20 + (390 - strlen(fullword) * 20) / 2, 100, 255, "%c", fullword[c]); // reveal the letter
				      play_sample(data[BANG_WAV].dat, 128, 128, 1000, 0); // bang
				   	rest(1000);
         	   	is_there = 1; // the letter is present
					}
               else if (!letter[c]) // the letter is still hidden
               	all_done = 0; // the player has not yet won
            }
	         if (!is_there) // the letter is not present
	         	addpart(&dead, deadman); // add one body part
	      }
         else
         {	textprintf_centre(answer, font, 180, 200, 255, "That letter has already been chosen.");
         	rest(1000);
            while (keypressed()) readkey();
            textprintf_centre(answer, font, 180, 200, 0, "That letter has already been chosen.");
         }
		}

  		if (all_done) // the player has won
      {	win = 1;
      	rest(1000);
      	break;
      }

      if (dead >= 6) // the player has lost
      {	win = 0;
      	for (int c = 0; c < strlen(fullword); c++) // reveal the rest of the word
         {	if (!letter[c]) // the letter is still hidden
         	{  textprintf_centre(answer, data[BIG_FONT].dat, c * 20 + (390 - strlen(fullword) * 20) / 2, 100, 255, "%c", fullword[c]);
			      play_sample(data[BANG_WAV].dat, 128, 128, 1000, 0);
			   	rest(1000);
            }
         }
         rest (1000);
      	break;
      }
   }
   fade_out(3);
   rest(200);
	return win;
}

//////////////////// Win Screen //////////////

void win_screen()
{
	clear(screen);
   blit(data[GAMEBACK_PIC].dat, screen, 0, 0, 0, 0, 640, 480);
   blit(data[FLICBACK_PIC].dat, screen, 0, 0, 150, 110, 340, 260); // cut out square in middle
	BITMAP* window = create_sub_bitmap(screen, 160, 120, 320, 240); // allows FLIC playing

   // there would be a cool animation here, but I can't get AA to cooperate
   // with the palette.

   textprintf_centre(window, font, 160, 116, 255, "YOU WIN!!!");
   fade_in(data[GAMESCREEN_PAL].dat, 3);
   rest(2000);
   fade_out(3);
   rest(200);
}

//////////////////// Lose Screen ///////////////

void lose_screen()
{
	clear(screen);
   blit(data[GAMEBACK_PIC].dat, screen, 0, 0, 0, 0, 640, 480);
   blit(data[FLICBACK_PIC].dat, screen, 0, 0, 150, 110, 340, 260); // cut out square in middle
	BITMAP* window = create_sub_bitmap(screen, 160, 120, 320, 240); // allows FLIC playing

   // ditto

   textprintf_centre(window, font, 160, 116, 255, "YOU LOSE!!!");
   fade_in(data[GAMESCREEN_PAL].dat, 3);
   play_midi(data[DEAD_MID].dat, 0); // play the death song
   while (midi_pos != -1 && !keypressed()); // while the midi's not done
   stop_midi();
   fade_out(3);
   rest(200);
}

//////////////////// Main Line //////////////////

int main(int argc, char* argv[])
{	time_t t; // needed for randomization
   srand((unsigned) time(&t)); // seed randomizer

	allegro_init();
	// load the datafile "hangman.dat" into memory
	char buf[80];
   strcpy(buf, argv[0]);
   strcpy(get_filename(buf), "hangman.dat");
   data = load_datafile(buf);
   if (!data)
   { 	allegro_exit();
      printf("Error loading hangman.dat!\n\n");
      getch();
      return 1;
   }

	install_keyboard(); // needed for readkey(), etc.
   install_timer(); // needed for mouse routines
   install_mouse();
   install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, 0);
   set_volume (128, 255); // don't forget to crank your volume when you play!
   set_gfx_mode(GFX_AUTODETECT, 640, 480, 0, 0);

   set_palette(data[GAMESCREEN_PAL].dat);

   title_screen();
   while (1)
	{	int choice = menu_screen(); // get the user's choice
      if (choice <= 4) // they want to play
      { 	int win = game_play(choice); // run the game
	   	if (win == 1) // they won
 		  		win_screen();
  	 		else if (!win) // they lost
   			lose_screen();
      }
      else if (choice == 5) // they want instructions
      	instruct_screen();
      else // they want to quit
      	break;
   }
}
