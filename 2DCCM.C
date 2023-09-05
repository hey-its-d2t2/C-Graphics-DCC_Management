/* Institute management software - DCC Classes Bhagalpur
Developed by : Deepak Singh
Email : deepsinghkumar01@gmail.com
*/
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
//#include<add_notes.h>
union REGS i,o,in,out;
int x,n,y;
//Function Decleration
void outline();
void welcome_screen();
void exit_screen();
void login_menu();
void cn();
void login_mouse();
void ad_login();
void ad_login_mouse();
void password_input();
void ad_password_niput();
void pas_setting();
void setting_mouse();
/* Administrator Main Screen */
void admin_main();
void mouse_ad_main_sc();
void add_notes_main_mouse();
// Student menu Mouse Detection
void student_menu_mouse();
// Student Admision Semester Selection window
void semester_selection_adm_window();
// Mouse Detection For Semester Selection Adm Window
void mouse_semester_selection_adm_window();
//semester selection for viewing details of students
void semester_selection_view_window();
// Mouse Detection for semester selection for viwing student details
void mouse_selection_view_window();
// Delete student Recoard window for each semester
void semester_selection_delete_window();
//Mouse Detection for semester selection window for deleating student details
void mouse_selection_delete_window();
//teacher moues  selection menu
void teacher_menu_mouse();
// Semester selection for add techer
void select_semester_add_teacher();
//Semester selection for remove teacheer
void select_semester_rem_teacher();
//Semestyer Selection For View Teacher
void select_semester_view_teacher();
// Mouse Detection for semester sslection for add teacher
void mouse_semester_add_teacher();
//Mouse Detection For semester selection for remove teacher
void mouse_semester_rem_teacher();
//Mouse detection for seester selsction for view teacher
void mouse_semester_view_teacher();
//detelte notes main screen for deleating notes eachn sem one by one
void delete_notes_main_screen();
// Mouse Detection For Delete Notes Main Screen
void mouse_delete_notes_main_screen();
// view notes main screen for viewing notes for each sem one by one
void view_notes_main_screen();
//Mouse Detection For View Notes  Main Screen Screen
void mouse_view_notes_main_screen();
//Mouse Detection For 1st Sem For Adding Notes
void  mouse_add_notes_1st_sem();
//Mouse Detection For 2nd  Sem For Adding Notes
void mouse_add_notes_2nd_sem();
//Mouse Detection For 3rd  Sem For Adding Notes
void mouse_add_notes_3rd_sem();
//Mouse Detection For 4th  Sem For Adding Notes
void mouse_add_notes_4th_sem();
//Mouse Detection For 5th  Sem For Adding Notes
void mouse_add_notes_5th_sem();
//Mouse Detection For 6th  Sem For Adding Notes
void mouse_add_notes_6th_sem();
//Mouse Detection for Delete Notes For 1st sem
void mouse_delete_notes_1st_sem();
//Mouse Detection for Delete Notes For 22n sem
void mouse_delete_notes_2nd_sem();
//Mouse Detection for Delete Notes For 3rd sem
void mouse_delete_notes_3rd_sem();
//Mouse Detection for Delete Notes For 4th sem
void mouse_delete_notes_4th_sem();
//Mouse Detection for Delete Notes For 5th sem
void mouse_delete_notes_5th_sem();
//Mouse Detection for Delete Notes For 5th sem
void mouse_delete_notes_6th_sem();

//*********
//Notes Screen
void notes_menu_mouse();
void add_notes_main_screen();
//Add Notes (writing) Sereen....
// 1st Sem.
void  write_notes_1st_sem_101_secrrn();
void  write_notes_1st_sem_102_screen();
void  write_notes_1st_sem_103_screen();
void  write_notes_1st_sem_104_screen();
void  write_notes_1st_sem_105_screen();
void  write_notes_1st_sem_106_screen();
// passwod variable
int k=0,j=0;
char name2[10],ch;
char pas2[6];
/* Teacher Login Functions */
//Semester Selection Window For Login Teacher
void teacher_log_sem_selection_window();
//mouse Detection for Login as  teacher for each semester
void mouse_teacher_log_sem_selection_window();




/* Mouse */
int initialize_mouse()
{
    i.x.ax=0;
    int86(0x33,&i,&o);
    return 0;
}
int show_mouse()
{
    i.x.ax=1;
    int86(0x33,&i,&o);
    return 0;
}
int get_mouse()
{
    i.x.ax=3;
    int86(0x33,&i,&o);
    return 0;

}
/* this function for getting the mouse position*/
void check_button_status()
{
while(!kbhit())
{
in.x.ax=3;
int86(0x33,&in,&out);
if(out.x.bx==1)
{
printf("\n Left Button is Pressed !");
x=out.x.cx;
y=out.x.dx;
printf("\n X= %d and y= %d",x,y);
}
if(out.x.bx==2)
printf("\n Right Button is Pressed !");
delay(100);
}
}
/* outline of every window */
void outline()
{
	cleardevice();
	 /* top  horizontal line */
	setcolor(15);
	line(0,18,640,18);
	line(0,19,640,19);
	line(0,20,640,20);
	line(0,21,640,21);
	line(0,22,640,22);
	setfillstyle(1,3);
	floodfill(0,0,15);
	/* Bottom Horizontal line */
	  setcolor(15);
	  line(0,455,640,455);
	  line(0,456,640,456);
	  line(0,457,640,457);
	  line(0,458,640,458);
	  line(0,459,640,459);
	  setfillstyle(1,3);
	  floodfill(0,460,15);
	  /* left vertical line */
	 setcolor(15);
	 line(13,454,13,20);
	 line(12,454,12,20);
	 line(11,454,11,20);
	 line(10,454,10,20);
	 setfillstyle(1,3);
	 floodfill(0,9,15);
	/* right vertical line */
	 setcolor(15);
	 line(620,454,620,18);
	 line(619,454,619,18);
	 line(618,454,618,18);
	 line(617,454,617,18);
	/* left side bar fill */
	 setfillstyle(1,3);
	 bar(0,18,10,459);
       /* right side bar fill */
	 setfillstyle(1,3);
	 bar(650,18,621,459);

}
/* Starting scerrn */
void welcome_screen()
{
	int oi;
	cleardevice();
	outline();
	line(14,425,616,425);
	setfillstyle(1,9);
	bar(14,426,616,456);
	settextstyle(1,0,4);
	setcolor(14);
	settextstyle(1,0,4);
	setcolor(14);
	outtextxy(120,420," DEEPAK COMPUTER CENTER ");
	outtextxy(121,420," DEEPAK COMPUTER CENTER ");
	outtextxy(122,420," DEEPAK COMPUTER CENTER ");
	gotoxy(30,14);
	for(oi=0;oi<25;oi++){printf("%c",196);}
	gotoxy(30,15);
	sound(999);
	printf("%c%c%c",4,3,4);
	delay(50);printf("  WELC");delay(65);printf("OME TO");delay(50);
	printf(" DCC  %c%c%c",4,3,4,4,3,4);
	gotoxy(30,16);
	for(oi=0;oi<25;oi++){printf("%c",196);}
	delay(300);
	//Progressbnar
	setlinestyle(0,0,1);
	rectangle(234,288,437,270);
	rectangle(234,289,438,271);
	for(oi=0;oi<136;oi++){
	setfillstyle(1,1);
	bar(235,287,300+oi,273);
	delay(10);
	}
	nosound();
	delay(200);
	sound(9999);
	delay(30);
	nosound();
	cleardevice();
	outline();
	login_menu();
}
/* center name for login  menu      */
void cn()
{
	setfillstyle(1,9);
	bar(14,23,616,58);
	line(14,58,616,58);
	settextstyle(1,0,4);
	setcolor(14);
	outtextxy(130,20,"DEEPAK COMPUTER CENTER");
	outtextxy(131,20,"DEEPAK COMPUTER CENTER");
	outtextxy(132,20,"DEEPAK COMPUTER CENTER");
}
/* login Menu */
void login_menu()
{
	cleardevice();
	outline();
	cn();
	//menu
	//outline
	setcolor(15);
	//outer
	rectangle(145,95,530,405);
	setfillstyle(1,3);
	bar(146,96,529,404);
	//inner
	setcolor(15);
	rectangle(150,100,525,400);
	setfillstyle(1,7);
	bar(151,101,524,399);
	//for next
	//login
	setcolor(15);
       //inner
	setlinestyle(0,0,1);
	rectangle(200,100,470,130);
	//outer
	setlinestyle(0,1,1);
	rectangle(198,100,472,132);
	//colour
	setfillstyle(1,3);
	bar(201,101,469,129);
	settextstyle(1,0,1);
	outtextxy(285,100,"L O G I N As !...");

	//Administator
	setlinestyle(0,0,1);
	rectangle(231,171,435,200);
	rectangle(231,171,436,201);
	setfillstyle(1,1);
	bar(232,173,434,199);
	settextstyle(0,0,1);
	outtextxy(278,180,"ADMINISTRATOR...");
	//Teacher
	setfillstyle(1,1);
	bar(232,250,437,226);
	setlinestyle(0,0,1);
	rectangle(231,249,438,225);
	rectangle(231,250,439,226);
	settextstyle(0,0,1);
	outtextxy(300,233,"TEACHER...");
	//Student
	setfillstyle(1,1);
	bar(232,299,435,272);
	settextstyle(0,0,1);
	setlinestyle(0,0,1);
	rectangle(231,299,437,272);
	rectangle(231,299,438,273);
	outtextxy(299,282,"STUDENT...");
	//Exit
	setlinestyle(0,0,1);
	setfillstyle(1,1);
	bar(285,327,380,355);
	rectangle(285,325,381,356);
	rectangle(285,325,382,357);
	settextstyle(1,0,2);
	outtextxy(313,330,"EXIT");
	delay(20);
	login_mouse();
}
/* Mouse Detection for login menu */
void login_mouse()
{
	//initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
	while(1)//!kbhit())
      // while(!kbhit())
      {
		 o.x.bx=0;
		 show_mouse();
		 get_mouse();
	       if(o.x.bx==1&&o.x.cx<435&&o.x.cx>231&&o.x.dx<207&&o.x.dx>170)
	       {
			sound(999);
			setcolor(8);
			setlinestyle(0,0,1);
			rectangle(231,171,435,200);
			rectangle(231,171,436,201);
			setfillstyle(1,14);
			bar(232,173,434,199);
			setcolor(8);
			settextstyle(0,0,1);
			outtextxy(278,180,"ADMINISTRATOR...");
			delay(250);
			nosound();
			cleardevice();
			ad_login();

		}
		if(o.x.bx==1&&o.x.cx<435&&o.x.cx>231&o.x.dx<250&&o.x.dx>220)
		{
			sound(999);
			setfillstyle(1,14);
			bar(232,250,437,226);
			setcolor(8);
			setlinestyle(0,0,1);
			rectangle(231,249,438,225);
			rectangle(231,250,439,226);
			settextstyle(0,0,1);
			outtextxy(300,233,"TEACHER...");
			delay(250);
			o.x.bx=0;
			nosound();
			cleardevice();
			login_menu();
		   //	teacher_log_sem_selection_window();
	       }
	       if(o.x.bx==1&&o.x.cx<435&&o.x.cx>231&&o.x.dx<300&&o.x.dx>270)
	       {
			sound(999);
			setfillstyle(1,14);
			bar(232,299,435,272);
			setcolor(8);
			settextstyle(0,0,1);
			setlinestyle(0,0,1);
			rectangle(231,299,437,272);
			rectangle(231,299,438,273);
			outtextxy(299,282,"STUDENT...");
			delay(250);
			nosound();
			cleardevice();
		   //	goto again;
			login_menu();
		}
		if(o.x.bx==1&&o.x.cx<385&&o.x.cx>285&&o.x.dx<360&&o.x.dx>320)
		{
			sound(999);
			setlinestyle(0,0,1);
			setfillstyle(1,1);
			bar(285,327,380,355);
			setcolor(8);
			rectangle(285,325,381,356);
			rectangle(285,325,382,357);
			settextstyle(1,0,2);
			outtextxy(313,330,"EXIT");
			cleardevice();
			delay(250);
			nosound();
			cleardevice();
			exit_screen();
		}

	}

}

// password input function is copied in pasinf.c
// when make the function paste here,all including function,
//void password_input()
//void ad_login_mouse()  and arrange the function
/*this function for administotar login */
void ad_login()
{
	clrscr();
	cleardevice();
	outline();
	cn();
	/* outline */
	setcolor(15);
	rectangle(120,110,520,330);
	rectangle(121,111,521,329);
	rectangle(119,109,519,328);
	rectangle(121,111,521,151);
	rectangle(121,111,521,152);
	setfillstyle(1,7);
	bar(122,112,518,150);
	setfillstyle(1,3);
	bar(122,153,518,327);
	setcolor(4);
	settextstyle(1,0,4);
	outtextxy(220,110,"ADMINISTRATOR");
	outtextxy(221,110,"ADMINISTRATOR");
	/*Administator Setting - password ,name */
	circle(158,130,18);
	setfillstyle(7,14);
	bar(166,120,150,141);
	/* name */
	setcolor(15);
	rectangle(171,170,261,201);
	rectangle(172,171,260,200);
	setfillstyle(1,5);
	bar(173,172,259,199);
	settextstyle(1,0,2);
	outtextxy(187,172,"Name");
	setfillstyle(1,15);
	bar(276,172,470,200);
	setcolor(1);
	rectangle(274,170,470,200);
	rectangle(275,171,471,201);
	/* Pasword */
	setcolor(15);
	rectangle(169,220,263,250);
	rectangle(170,221,262,249);
	setfillstyle(1,5);
	bar(171,222,261,248);
	settextstyle(1,0,1);
	outtextxy(174,225,"Password");

	setfillstyle(1,15);
	bar(276,224,470,248);
	setcolor(1);
	rectangle(274,222,470,250);
	rectangle(275,223,471,249);
	/* Ok button */
	setcolor(15);
	rectangle(235,270,300,299);
	rectangle(236,271,301,300);
	setfillstyle(1,5);
	bar(237,272,299,298);
	settextstyle(1,0,2);
	outtextxy(255,272,"Ok");
	/* Cancle button */
	setcolor(15);
	rectangle(330,270,400,299);
	rectangle(331,271,401,298);
	setfillstyle(1,5);
	bar(332,272,399,297);
	settextstyle(1,0,1);
	outtextxy(338,274,"Cancle");
	password_input();
	cleardevice();
}
//Password Setting Box Function
void pas_setting()
{
       //	char setting_name[10],setting_pas[10];
	cleardevice();
	outline();
	cn();
	/* outline */
	setcolor(15);
	rectangle(120,110,520,330);
	rectangle(121,111,521,329);
	rectangle(119,109,519,328);
	rectangle(121,111,521,151);
	rectangle(121,111,521,152);
	setfillstyle(1,3);
	bar(122,112,518,150);
	setfillstyle(1,7);
	bar(122,153,518,327);
	setcolor(14);
	settextstyle(1,0,3);
	outtextxy(145,111,"Set Your Name and Password");
	outtextxy(145,111,"Set Your Name and Password");
	/* name */
	setcolor(15);
	rectangle(171,170,261,201);
	rectangle(172,171,260,200);
	setfillstyle(1,5);
	bar(173,172,259,199);
	settextstyle(1,0,2);
	outtextxy(187,172,"Name");
	setfillstyle(1,15);
	bar(276,172,470,200);
	setcolor(1);
	rectangle(274,170,470,200);
	rectangle(275,171,471,201);
	/* Pasword */
	setcolor(15);
	rectangle(169,220,263,250);
	rectangle(170,221,262,249);
	setfillstyle(1,5);
	bar(171,222,261,248);
	settextstyle(1,0,1);
	outtextxy(174,225,"Password");

	setfillstyle(1,15);
	bar(276,224,470,248);
	setcolor(1);
	rectangle(274,222,470,250);
	rectangle(275,223,471,249);
	/* Ok button */
	setcolor(15);
	rectangle(235,270,300,299);
	rectangle(236,271,301,300);
	setfillstyle(1,5);
	bar(237,272,299,298);
	settextstyle(1,0,2);
	outtextxy(255,272,"Ok");
	/* Cancle button */
	setcolor(15);
	rectangle(330,270,400,299);
	rectangle(331,271,401,298);
	setfillstyle(1,5);
	bar(332,272,399,297);
	settextstyle(1,0,1);
	outtextxy(338,274,"Cancle");
	setting_mouse();
}
// Setting Mouse Detection
void setting_mouse()
{
	//initilizing mouse for this block
	initialize_mouse();
	show_mouse();
 //     check_button_status();
	//while(!kbhit())
	while(1)
       {
		 o.x.bx=0;
		 show_mouse();
		 get_mouse();
	       if(o.x.bx==1&&o.x.cx<299&&o.x.cx>234&&o.x.dx<299&&o.x.dx>271)
	       {
			// Ok Button
			sound(999);
			setcolor(15);
			rectangle(235,270,300,299);
			rectangle(236,271,301,300);
			setfillstyle(1,14);
			bar(237,272,299,298);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(255,272,"Ok");
			nosound();
			cleardevice();
			ad_login();

		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>330&o.x.dx<299&&o.x.dx>270)
		{
			//Cancle Button
			sound(999);
			setcolor(15);
			rectangle(330,270,400,299);
			rectangle(331,271,401,298);
			setfillstyle(1,14);
			bar(332,272,399,297);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(338,274,"Cancle");
			nosound();
			cleardevice();
			login_menu();
	       }
       }
}
//Password input pfr administator login
void password_input()
{
	int xp=280,yp=170;
	setcolor(3);
	while((name2[k]=getch())!=13)
	{
		settextstyle(7,0,4);
		outtextxy(xp,yp,"*");
		sound(1000);
		delay(100);
		xp+=15;
		nosound();
	}
	name2[k]='\0';
	xp=283;
	yp=218;
	while((pas2[j]=getch())!=13)
	{
			outtextxy(xp,yp,"*");
			sound(1000);
			delay(100);
			xp+=15;
			nosound();
	}
	pas2[j]='\0';
	ad_login_mouse();
}
/* Mouse Detection For Administrator Pasword Screen */
void ad_login_mouse()
{
	//initilizing mouse for this block
	initialize_mouse();
	show_mouse();
 //     check_button_status();
       //	while(!kbhit())
       while(1)
       {
		 o.x.bx=0;
		 show_mouse();
		 get_mouse();
	       if(o.x.bx==1&&o.x.cx<299&&o.x.cx>234&&o.x.dx<299&&o.x.dx>271)
	       {
			// Ok Button
			sound(999);
			setcolor(15);
			rectangle(235,270,300,299);
			rectangle(236,271,301,300);
			setfillstyle(1,14);
			bar(237,272,299,298);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(255,272,"Ok");
			nosound();
			/* Administrator Main Screen */
			admin_main();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>330&o.x.dx<299&&o.x.dx>270)
		{
			//Cancle Button
			sound(999);
			setcolor(15);
			rectangle(330,270,400,299);
			rectangle(331,271,401,298);
			setfillstyle(1,14);
			bar(332,272,399,297);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(338,274,"Cancle");
			nosound();
			cleardevice();
			login_menu();
	       }
		if(o.x.bx==1&&o.x.cx<175&&o.x.cx>140&o.x.dx<145&&o.x.dx>113)
		{
		      //Password Setting
			sound(999);
			circle(158,130,18);
			setfillstyle(7,14);
			bar(166,120,150,141);
			nosound();
			cleardevice();
			// call Password Setting Dilogbox
			pas_setting();
		}
       }
}
/* Administrator Main Screen */
void admin_main()
{       cleardevice();
	//Center name
	setcolor(15);
	line(2,444,669,444);
	setfillstyle(1,9);
	bar(2,445,669,480);
	settextstyle(1,0,4);
	setcolor(14);
	settextstyle(1,0,4);
	setcolor(14);
	outtextxy(120,441," DEEPAK COMPUTER CENTER ");
	outtextxy(121,441," DEEPAK COMPUTER CENTER ");
	outtextxy(122,441," DEEPAK COMPUTER CENTER ");
	//Ribbon
	setfillstyle(1,7);
	bar(0,0,670,25);
	setcolor(14);
	//Top line
	line(0,0,670,0);
	line(1,0,670,0);
	//Middle line
	line(0,26,670,26);
	line(0,27,670,27);
	//left line
	line(0,0,0,640);
	line(1,0,1,640);
	//Right line
	line(639,0,639,640);
	line(638,0,638,640);
	// Tabs
	setcolor(15);
	//Back
	//rectangle(2,1,70,25);
	setcolor(9);
	settextstyle(1,0,2);
	outtextxy(10,0,"Back");
	//Student
	setcolor(6);
      //	rectangle(160,1,260,25);
	setcolor(9);
	settextstyle(1,0,2);
	outtextxy(172,0,"Student");
	//Teacher
	setcolor(3);
//	rectangle(275,1,380,25);
	setcolor(9);
	settextstyle(1,0,2);
	outtextxy(290,0,"Teacher");
	//Notets
	setcolor(5);
      //	rectangle(400,1,480,25);
	setcolor(9);
	settextstyle(1,0,2);
	outtextxy(415,0,"Notes");
	//Exit
       //	rectangle(570,1,638,25);
	setcolor(9);
	settextstyle(1,0,2);
	outtextxy(585,0,"Exit");
	mouse_ad_main_sc();
}
//Admin Main Scren Mouse Detection
void mouse_ad_main_sc()
{
	//initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
   //	while(!kbhit())
   while(1)
      {
		  o.x.bx=0;
		 show_mouse();
		 get_mouse();
	       if(o.x.bx==1&&o.x.cx<70&&o.x.cx>2&&o.x.dx<25&&o.x.dx>1)
	       {
			//Back
			sound(999);
			setfillstyle(1,14);
			bar(2,1,70,25);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(10,0,"Back");
			delay(200);
			nosound();
			cleardevice();
			login_menu();
		}
		if(o.x.bx==1&&o.x.cx<638&&o.x.cx>570&&o.x.dx<25&&o.x.dx>1)
		{
			//Exit
			sound(999);
			setlinestyle(0,0,2);
			rectangle(569,1,639,25);
			setfillstyle(1,14);
			bar(570,1,638,25);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(585,0,"Exit");
			nosound();
			delay(200);
			cleardevice();
			exit_screen();
		}
		if(o.x.bx==1&&o.x.cx<260&&o.x.cx>160&&o.x.dx<25&&o.x.dx>1)
		{
			//Student
			sound(999);
			setlinestyle(0,0,2);
			rectangle(159,1,261,25);
			setfillstyle(1,14);
			bar(160,1,260,25);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(172,0,"Student");
			nosound();
			delay(200);
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(159,30,330,120);
			setfillstyle(1,3);
			bar(160,31,329,119);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(170,32,"New Admission");
			setcolor(15);
			line(169,62,329,62);
			setcolor(14);
			outtextxy(170,66,"View Students");
			setcolor(15);
			line(169,90,329,90);
			setcolor(14);
			outtextxy(170,93,"Delete Students");
			delay(100);
			student_menu_mouse();
		      //	cleardevice();
			//admin_main();

		}
		if(o.x.bx==1&&o.x.cx<380&&o.x.cx>275&&o.x.dx<25&&o.x.dx>1)
		{
			//Teacher
			sound(999);
			setlinestyle(0,0,2);
			rectangle(274,1,381,25);
			setfillstyle(1,14);
			bar(275,1,380,25);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(290,0,"Teacher");
			nosound();
			delay(200);
			//Showing Menu
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(274,27,457,115);
			setfillstyle(1,3);
			bar(275,28,456,114);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(288,30,"Add Teacher");
			setcolor(15);
			line(288,58,456,58);
			setcolor(14);
			outtextxy(288,60,"Remove Teacher");
			setcolor(15);
			line(288,88,456,88);
			setcolor(14);
			outtextxy(288,90,"View Teacher");
			delay(100);
			teacher_menu_mouse();

		}
		if(o.x.bx==1&&o.x.cx<480&&o.x.cx>400&&o.x.dx<25&&o.x.dx>1)
		{
			//Notets
			sound(999);
			setlinestyle(0,0,2);
			rectangle(399,1,481,25);
			setfillstyle(1,14);
			bar(400,1,480,25);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(415,0,"Notes");
			nosound();
			delay(200);
			//Showing Menu
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(400,27,558,115);
			setfillstyle(1,3);
			bar(401,28,557,114);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(415,30,"Add Notes...");
			setcolor(15);
			line(415,58,557,58);
			setcolor(14);
			outtextxy(415,60,"Delete Notes...");
			setcolor(15);
			line(415,88,557,88);
			setcolor(14);
			outtextxy(415,90,"View Notes...");
			 delay(100);
			notes_menu_mouse();
		}
      }
}
// Student menu Mouse Detection
void student_menu_mouse()
{
	//initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
	while(1)//!kbhit())
      // while(!kbhit())
      {
		 o.x.bx=0;
		 show_mouse();
		 get_mouse();
		 if(o.x.bx==1&&o.x.cx<330&&o.x.cx>159&&o.x.dx<62&&o.x.dx>30)
		 {
			//New Admission
			sound(999);
			setfillstyle(1,14);
			bar(161,29,329,61);
			setcolor(8);
			rectangle(160,30,330,62);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(170,32,"New Admission");
			delay(250);
			nosound();
			cleardevice();
			semester_selection_adm_window();
		}
		 if(o.x.bx==1&&o.x.cx<330&&o.x.cx>159&&o.x.dx<84&&o.x.dx>68)
		{
			//View Students
			sound(999);
			setfillstyle(1,14);
			bar(161,63,329,89);
			setlinestyle(1,0,15);
			setcolor(8);
			rectangle(160,62,330,90);
			setcolor(8);
			outtextxy(170,66,"View Students");
			delay(250);
			nosound();
			cleardevice();
			semester_selection_view_window();
		}

		 if(o.x.bx==1&&o.x.cx<330&&o.x.cx>159&&o.x.dx<120&&o.x.dx>91)
		{
			//Delete Students
			sound(999);
			setfillstyle(1,14);
			bar(161,91,329,119);
			setlinestyle(1,0,15);
			setcolor(8);
			rectangle(160,90,330,120);
			setcolor(8);
			outtextxy(170,93,"Delete Students");
			delay(250);
			nosound();
			cleardevice();
			semester_selection_delete_window();
		}
	  }
}
// Student Admision Semester Selection window
void semester_selection_adm_window()
{
	cleardevice();
	outline();
	cn();
	/* outline */
	setcolor(15);
	rectangle(120,110,520,400);
	rectangle(121,111,520,400);
	rectangle(119,109,521,401);
	rectangle(121,111,521,152);
	setfillstyle(1,3);
	bar(122,112,519,151);
	setfillstyle(1,7);
	bar(122,153,519,399);
	setcolor(14);
	settextstyle(1,0,3);
	outtextxy(145,111,"Select Semester For Admission");
	outtextxy(145,111,"Select Semester For Admission");
	//Back Button
	setcolor(15);
	rectangle(121,230,150,310);
	setfillstyle(1,8);
	bar(122,231,149,309);
	settextstyle(1,0,3);
	outtextxy(125,232,"B");
	outtextxy(125,246,"a");
	outtextxy(125,260,"c");
	outtextxy(125,277,"k");
	//Exit Button
	setcolor(15);
	rectangle(490,231,519,309);
	setfillstyle(1,8);
	bar(491,232,518,308);
	setcolor(15);
	outtextxy(495,232,"E");
	outtextxy(495,246,"x");
	outtextxy(495,265,"i");
	outtextxy(495,281,"t");
	//1st sem. Button
	setcolor(15);
	rectangle(230,160,400,190);
	setfillstyle(1,5);
	bar(231,161,399,189);
	settextstyle(1,0,2);
	outtextxy(270,161,"1st Sem.");
	outtextxy(270,161,"1st Sem.");
	//2nd Sem. Button
	setcolor(15);
	rectangle(231,200,400,230);
	setfillstyle(1,5);
	bar(232,201,399,229);
	outtextxy(270,202,"2nd Sem.");
	outtextxy(270,202,"2nd Sem.");
	//3rd Sem. Button
	setcolor(15);
	rectangle(231,240,400,270);
	setfillstyle(1,5);
	bar(232,241,399,269);
	outtextxy(270,243,"3rd Sem.");
	outtextxy(270,243,"3rd Sem.");
	//4th Sem. Button
	setcolor(15);
	rectangle(231,280,400,310);
	setfillstyle(1,5);
	bar(232,281,399,309);
	outtextxy(270,283,"4th Sem.");
	outtextxy(270,283,"4th Sem.");
	//5th Sem. Button
	setcolor(15);
	rectangle(231,320,400,350);
	setfillstyle(1,5);
	bar(232,321,399,349);
	outtextxy(270,320,"5th Sem.");
	outtextxy(270,320,"5th Sem.");
	//6th Sem Button
	setcolor(15);
	rectangle(231,360,400,390);
	setfillstyle(1,5);
	bar(232,361,399,389);
	outtextxy(270,360,"6th Sem.");
	outtextxy(270,360,"6th Sem.");
	mouse_semester_selection_adm_window();

}
// Mouse Detection For Semester Selection Adm Window
void mouse_semester_selection_adm_window()
{
	//initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
	while(1)//!kbhit())
      // while(!kbhit())
       {
		 o.x.bx=0;
		 show_mouse();
		 get_mouse();
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<200&&o.x.dx>160)
		 {
			//1st Sem. clicking
			sound(999);
			setcolor(15);
			rectangle(230,160,400,190);
			setfillstyle(1,14);
			bar(231,161,399,189);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(270,161,"1st Sem.");
			outtextxy(270,161,"1st Sem.");
			delay(250);
			nosound();
			cleardevice();
			semester_selection_adm_window();
		}
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<230&&o.x.dx>200)
		{
			//2nd Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,200,400,230);
			setfillstyle(1,14);
			bar(232,201,399,229);
			setcolor(8);
			outtextxy(270,202,"2nd Sem.");
			outtextxy(270,202,"2nd Sem.");
			delay(100);
			nosound();
			cleardevice();
			semester_selection_adm_window();
		}
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<270&&o.x.dx>240)
		{
			//3rd Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,240,400,270);
			setfillstyle(1,14);
			bar(232,241,399,269);
			setcolor(8);
			outtextxy(270,243,"3rd Sem.");
			outtextxy(270,243,"3rd Sem.");
			delay(100);
			nosound();
			cleardevice();
			semester_selection_adm_window();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<310&&o.x.dx>280)
		{
			//4th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,280,400,310);
			setfillstyle(1,14);
			bar(232,281,399,309);
			setcolor(8);
			outtextxy(270,283,"4th Sem.");
			outtextxy(270,283,"4th Sem.");
			delay(100);
			nosound();
			cleardevice();
			semester_selection_adm_window();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<350&&o.x.dx>320)
		{
			//5th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,320,400,350);
			setfillstyle(1,14);
			bar(232,321,399,349);
			setcolor(8);
			outtextxy(270,320,"5th Sem.");
			outtextxy(270,320,"5th Sem.");
			delay(100);
			nosound();
			cleardevice();
			semester_selection_adm_window();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<390&&o.x.dx>360)
		{
			//6th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,360,400,390);
			setfillstyle(1,14);
			bar(232,361,399,389);
			setcolor(8);
			outtextxy(270,360,"6th Sem.");
			outtextxy(270,360,"6th Sem.");
			delay(100);
			nosound();
			cleardevice();
			semester_selection_adm_window();
		}
		if(o.x.bx==1&&o.x.cx<150&&o.x.cx>127&&o.x.dx<310&&o.x.dx>230)
		{
			//Back Button  Clicking
			sound(999);
			setcolor(15);
			rectangle(121,230,150,310);
			setfillstyle(1,14);
			bar(122,231,149,309);
			setcolor(8);
			settextstyle(1,0,3);
			outtextxy(125,232,"B");
			outtextxy(125,246,"a");
			outtextxy(125,260,"c");
			outtextxy(125,277,"k");
			delay(100);
			nosound();
			cleardevice();
			admin_main();
		}
		if(o.x.bx==1&&o.x.cx<519&&o.x.cx>490&&o.x.dx<310&&o.x.dx>230)
		{
			//Exit Button  Clicking
			sound(999);
			setcolor(15);
			rectangle(490,231,519,309);
			setfillstyle(1,14);
			bar(491,232,518,308);
			setcolor(8);
			outtextxy(495,232,"E");
			outtextxy(495,246,"x");
			outtextxy(495,265,"i");
			outtextxy(495,281,"t");
			delay(250);
			nosound();
			cleardevice();
			exit_screen();
		}

	  }
}
// admission process for each semester








//semester selection for viewing details of students
void semester_selection_view_window()
{
	cleardevice();
	outline();
	cn();
	/* outline */
	setcolor(15);
	rectangle(120,110,520,400);
	rectangle(121,111,520,400);
	rectangle(119,109,521,401);
	rectangle(121,111,521,152);
	setfillstyle(1,3);
	bar(122,112,519,151);
	setfillstyle(1,7);
	bar(122,153,519,399);
	setcolor(14);
	settextstyle(1,0,3);
	outtextxy(123,111,"Select Semester For View Student");
	outtextxy(123,111,"Select Semester For View Student");
	//Back Button
	setcolor(15);
	rectangle(121,230,150,310);
	setfillstyle(1,8);
	bar(122,231,149,309);
	settextstyle(1,0,3);
	outtextxy(125,232,"B");
	outtextxy(125,246,"a");
	outtextxy(125,260,"c");
	outtextxy(125,277,"k");
	//Exit Button
	setcolor(15);
	rectangle(490,231,519,309);
	setfillstyle(1,8);
	bar(491,232,518,308);
	setcolor(15);
	outtextxy(495,232,"E");
	outtextxy(495,246,"x");
	outtextxy(495,265,"i");
	outtextxy(495,281,"t");
	//1st sem. Button
	setcolor(15);
	rectangle(230,160,400,190);
	setfillstyle(1,5);
	bar(231,161,399,189);
	settextstyle(1,0,2);
	outtextxy(270,161,"1st Sem.");
	outtextxy(270,161,"1st Sem.");
	//2nd Sem. Button
	setcolor(15);
	rectangle(231,200,400,230);
	setfillstyle(1,5);
	bar(232,201,399,229);
	outtextxy(270,202,"2nd Sem.");
	outtextxy(270,202,"2nd Sem.");
	//3rd Sem. Button
	setcolor(15);
	rectangle(231,240,400,270);
	setfillstyle(1,5);
	bar(232,241,399,269);
	outtextxy(270,243,"3rd Sem.");
	outtextxy(270,243,"3rd Sem.");
	//4th Sem. Button
	setcolor(15);
	rectangle(231,280,400,310);
	setfillstyle(1,5);
	bar(232,281,399,309);
	outtextxy(270,283,"4th Sem.");
	outtextxy(270,283,"4th Sem.");
	//5th Sem. Button
	setcolor(15);
	rectangle(231,320,400,350);
	setfillstyle(1,5);
	bar(232,321,399,349);
	outtextxy(270,320,"5th Sem.");
	outtextxy(270,320,"5th Sem.");
	//6th Sem Button
	setcolor(15);
	rectangle(231,360,400,390);
	setfillstyle(1,5);
	bar(232,361,399,389);
	outtextxy(270,360,"6th Sem.");
	outtextxy(270,360,"6th Sem.");
	mouse_selection_view_window();
}
// Mouse Detection for semester selection for viwing student details
void mouse_selection_view_window()
{
   //initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
	while(1)//!kbhit())
      // while(!kbhit())
       {
		 o.x.bx=0;
		 show_mouse();
		 get_mouse();
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<200&&o.x.dx>160)
		 {
			//1st Sem. clicking
			sound(999);
			setcolor(15);
			rectangle(230,160,400,190);
			setfillstyle(1,14);
			bar(231,161,399,189);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(270,161,"1st Sem.");
			outtextxy(270,161,"1st Sem.");
			delay(250);
			nosound();
			cleardevice();
			semester_selection_view_window();
		}
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<230&&o.x.dx>200)
		{
			//2nd Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,200,400,230);
			setfillstyle(1,14);
			bar(232,201,399,229);
			setcolor(8);
			outtextxy(270,202,"2nd Sem.");
			outtextxy(270,202,"2nd Sem.");
			delay(100);
			nosound();
			cleardevice();
			semester_selection_view_window();
		}
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<270&&o.x.dx>240)
		{
			//3rd Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,240,400,270);
			setfillstyle(1,14);
			bar(232,241,399,269);
			setcolor(8);
			outtextxy(270,243,"3rd Sem.");
			outtextxy(270,243,"3rd Sem.");
			delay(100);
			nosound();
			cleardevice();
			semester_selection_view_window();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<310&&o.x.dx>280)
		{
			//4th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,280,400,310);
			setfillstyle(1,14);
			bar(232,281,399,309);
			setcolor(8);
			outtextxy(270,283,"4th Sem.");
			outtextxy(270,283,"4th Sem.");
			delay(100);
			nosound();
			cleardevice();
			semester_selection_view_window();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<350&&o.x.dx>320)
		{
			//5th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,320,400,350);
			setfillstyle(1,14);
			bar(232,321,399,349);
			setcolor(8);
			outtextxy(270,320,"5th Sem.");
			outtextxy(270,320,"5th Sem.");
			delay(100);
			nosound();
			cleardevice();
			semester_selection_view_window();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<390&&o.x.dx>360)
		{
			//6th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,360,400,390);
			setfillstyle(1,14);
			bar(232,361,399,389);
			setcolor(8);
			outtextxy(270,360,"6th Sem.");
			outtextxy(270,360,"6th Sem.");
			delay(100);
			nosound();
			cleardevice();
			semester_selection_view_window();
		}
		if(o.x.bx==1&&o.x.cx<150&&o.x.cx>127&&o.x.dx<310&&o.x.dx>230)
		{
			//Back Button  Clicking
			sound(999);
			setcolor(15);
			rectangle(121,230,150,310);
			setfillstyle(1,14);
			bar(122,231,149,309);
			setcolor(8);
			settextstyle(1,0,3);
			outtextxy(125,232,"B");
			outtextxy(125,246,"a");
			outtextxy(125,260,"c");
			outtextxy(125,277,"k");
			delay(100);
			nosound();
			cleardevice();
			admin_main();
		}
		if(o.x.bx==1&&o.x.cx<519&&o.x.cx>490&&o.x.dx<310&&o.x.dx>230)
		{
			//Exit Button  Clicking
			sound(999);
			setcolor(15);
			rectangle(490,231,519,309);
			setfillstyle(1,14);
			bar(491,232,518,308);
			setcolor(8);
			outtextxy(495,232,"E");
			outtextxy(495,246,"x");
			outtextxy(495,265,"i");
			outtextxy(495,281,"t");
			delay(250);
			nosound();
			cleardevice();
			exit_screen();
		}

	  }

}
// Make Function for student details for each semester












// Delete student Recoard window for each semester
void semester_selection_delete_window()
{
	cleardevice();
	outline();
	cn();
	/* outline */
	setcolor(15);
	rectangle(120,110,520,400);
	rectangle(121,111,520,400);
	rectangle(119,109,521,401);
	rectangle(121,111,521,152);
	setfillstyle(1,3);
	bar(122,112,519,151);
	setfillstyle(1,7);
	bar(122,153,519,399);
	setcolor(14);
	settextstyle(1,0,3);
	outtextxy(123,111,"Select Semester For Delete Stud...");
	outtextxy(123,111,"Select Semester For Delete Stud...");
	//Back Button
	setcolor(15);
	rectangle(121,230,150,310);
	setfillstyle(1,8);
	bar(122,231,149,309);
	settextstyle(1,0,3);
	outtextxy(125,232,"B");
	outtextxy(125,246,"a");
	outtextxy(125,260,"c");
	outtextxy(125,277,"k");
	//Exit Button
	setcolor(15);
	rectangle(490,231,519,309);
	setfillstyle(1,8);
	bar(491,232,518,308);
	setcolor(15);
	outtextxy(495,232,"E");
	outtextxy(495,246,"x");
	outtextxy(495,265,"i");
	outtextxy(495,281,"t");
	//1st sem. Button
	setcolor(15);
	rectangle(230,160,400,190);
	setfillstyle(1,5);
	bar(231,161,399,189);
	settextstyle(1,0,2);
	outtextxy(270,161,"1st Sem.");
	outtextxy(270,161,"1st Sem.");
	//2nd Sem. Button
	setcolor(15);
	rectangle(231,200,400,230);
	setfillstyle(1,5);
	bar(232,201,399,229);
	outtextxy(270,202,"2nd Sem.");
	outtextxy(270,202,"2nd Sem.");
	//3rd Sem. Button
	setcolor(15);
	rectangle(231,240,400,270);
	setfillstyle(1,5);
	bar(232,241,399,269);
	outtextxy(270,243,"3rd Sem.");
	outtextxy(270,243,"3rd Sem.");
	//4th Sem. Button
	setcolor(15);
	rectangle(231,280,400,310);
	setfillstyle(1,5);
	bar(232,281,399,309);
	outtextxy(270,283,"4th Sem.");
	outtextxy(270,283,"4th Sem.");
	//5th Sem. Button
	setcolor(15);
	rectangle(231,320,400,350);
	setfillstyle(1,5);
	bar(232,321,399,349);
	outtextxy(270,320,"5th Sem.");
	outtextxy(270,320,"5th Sem.");
	//6th Sem Button
	setcolor(15);
	rectangle(231,360,400,390);
	setfillstyle(1,5);
	bar(232,361,399,389);
	outtextxy(270,360,"6th Sem.");
	outtextxy(270,360,"6th Sem.");
	mouse_selection_delete_window();

}
//Mouse Detection for semester selection window for deleating student details
void mouse_selection_delete_window()
{
   //initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
	while(1)//!kbhit())
      // while(!kbhit())
       {
		 o.x.bx=0;
		 show_mouse();
		 get_mouse();
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<200&&o.x.dx>160)
		 {
			//1st Sem. clicking
			sound(999);
			setcolor(15);
			rectangle(230,160,400,190);
			setfillstyle(1,14);
			bar(231,161,399,189);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(270,161,"1st Sem.");
			outtextxy(270,161,"1st Sem.");
			delay(250);
			nosound();
			cleardevice();
			semester_selection_delete_window();
		 }
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<230&&o.x.dx>200)
		{
			//2nd Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,200,400,230);
			setfillstyle(1,14);
			bar(232,201,399,229);
			setcolor(8);
			outtextxy(270,202,"2nd Sem.");
			outtextxy(270,202,"2nd Sem.");
			delay(100);
			nosound();
			cleardevice();
			semester_selection_delete_window();
		}
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<270&&o.x.dx>240)
		{
			//3rd Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,240,400,270);
			setfillstyle(1,14);
			bar(232,241,399,269);
			setcolor(8);
			outtextxy(270,243,"3rd Sem.");
			outtextxy(270,243,"3rd Sem.");
			delay(100);
			nosound();
			cleardevice();
			semester_selection_delete_window();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<310&&o.x.dx>280)
		{
			//4th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,280,400,310);
			setfillstyle(1,14);
			bar(232,281,399,309);
			setcolor(8);
			outtextxy(270,283,"4th Sem.");
			outtextxy(270,283,"4th Sem.");
			delay(100);
			nosound();
			cleardevice();
			semester_selection_delete_window();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<350&&o.x.dx>320)
		{
			//5th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,320,400,350);
			setfillstyle(1,14);
			bar(232,321,399,349);
			setcolor(8);
			outtextxy(270,320,"5th Sem.");
			outtextxy(270,320,"5th Sem.");
			delay(100);
			nosound();
			cleardevice();
			semester_selection_delete_window();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<390&&o.x.dx>360)
		{
			//6th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,360,400,390);
			setfillstyle(1,14);
			bar(232,361,399,389);
			setcolor(8);
			outtextxy(270,360,"6th Sem.");
			outtextxy(270,360,"6th Sem.");
			delay(100);
			nosound();
			cleardevice();
			semester_selection_delete_window();

		}
		if(o.x.bx==1&&o.x.cx<150&&o.x.cx>127&&o.x.dx<310&&o.x.dx>230)
		{
			//Back Button  Clicking
			sound(999);
			setcolor(15);
			rectangle(121,230,150,310);
			setfillstyle(1,14);
			bar(122,231,149,309);
			setcolor(8);
			settextstyle(1,0,3);
			outtextxy(125,232,"B");
			outtextxy(125,246,"a");
			outtextxy(125,260,"c");
			outtextxy(125,277,"k");
			delay(100);
			nosound();
			cleardevice();
			admin_main();
		}
		if(o.x.bx==1&&o.x.cx<519&&o.x.cx>490&&o.x.dx<310&&o.x.dx>230)
		{
			//Exit Button  Clicking
			sound(999);
			setcolor(15);
			rectangle(490,231,519,309);
			setfillstyle(1,14);
			bar(491,232,518,308);
			setcolor(8);
			outtextxy(495,232,"E");
			outtextxy(495,246,"x");
			outtextxy(495,265,"i");
			outtextxy(495,281,"t");
			delay(250);
			nosound();
			cleardevice();
			exit_screen();
		}

	  }

}
// Make function for deleating student details for each semester











//*****************************************************
//teacher mouse selection menu
void teacher_menu_mouse()
{
	//initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
   //	while(!kbhit())
	   while(1)
	  {
		  o.x.bx=0;
		 show_mouse();
		 get_mouse();
	       if(o.x.bx==1&&o.x.cx<457&&o.x.cx>275&&o.x.dx<58&&o.x.dx>28)
	       {
			//add teacher clicking
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(275,28,457,58);
			setfillstyle(1,14);
			bar(276,29,456,57);
			settextstyle(1,0,2);
			outtextxy(288,30,"Add Teacher");
			nosound();
			delay(250);
		      // admin_main();
		       cleardevice();
		      select_semester_add_teacher();
		}
		if(o.x.bx==1&&o.x.cx<457&&o.x.cx>275&&o.x.dx<88&&o.x.dx>58)
		{
			//Remove teacher clicking
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(275,58,457,88);
			setfillstyle(1,14);
			bar(276,59,456,87);
			settextstyle(1,0,2);
			outtextxy(288,60,"Add Teacher");
			nosound();
			delay(250);
		       //	admin_main();
		       cleardevice();
		       select_semester_rem_teacher();
		}
		if(o.x.bx==1&&o.x.cx<457&&o.x.cx>275&&o.x.dx<120&&o.x.dx>88)
		{
			//View teacher clicking
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(275,88,457,120);
			setfillstyle(1,14);
			bar(276,89,456,119);
			settextstyle(1,0,2);
			outtextxy(288,90,"View Teacher");
			nosound();
			delay(250);
		      //	admin_main();
		      cleardevice();
		      select_semester_view_teacher();

		}
	 }
}
// Semester selection for add techer
void select_semester_add_teacher()
{
	cleardevice();
	outline();
	cn();
	/* outline */
	setcolor(15);
	rectangle(120,110,520,400);
	rectangle(121,111,520,400);
	rectangle(119,109,521,401);
	rectangle(121,111,521,152);
	setfillstyle(1,3);
	bar(122,112,519,151);
	setfillstyle(1,7);
	bar(122,153,519,399);
	setcolor(14);
	settextstyle(1,0,3);
	outtextxy(123,111,"Select Semester For Add Teacher");
	outtextxy(123,111,"Select Semester For Add Teacher");
	//Back Button
	setcolor(15);
	rectangle(121,230,150,310);
	setfillstyle(1,8);
	bar(122,231,149,309);
	settextstyle(1,0,3);
	outtextxy(125,232,"B");
	outtextxy(125,246,"a");
	outtextxy(125,260,"c");
	outtextxy(125,277,"k");
	//Exit Button
	setcolor(15);
	rectangle(490,231,519,309);
	setfillstyle(1,8);
	bar(491,232,518,308);
	setcolor(15);
	outtextxy(495,232,"E");
	outtextxy(495,246,"x");
	outtextxy(495,265,"i");
	outtextxy(495,281,"t");
	//1st sem. Button
	setcolor(15);
	rectangle(230,160,400,190);
	setfillstyle(1,5);
	bar(231,161,399,189);
	settextstyle(1,0,2);
	outtextxy(270,161,"1st Sem.");
	outtextxy(270,161,"1st Sem.");
	//2nd Sem. Button
	setcolor(15);
	rectangle(231,200,400,230);
	setfillstyle(1,5);
	bar(232,201,399,229);
	outtextxy(270,202,"2nd Sem.");
	outtextxy(270,202,"2nd Sem.");
	//3rd Sem. Button
	setcolor(15);
	rectangle(231,240,400,270);
	setfillstyle(1,5);
	bar(232,241,399,269);
	outtextxy(270,243,"3rd Sem.");
	outtextxy(270,243,"3rd Sem.");
	//4th Sem. Button
	setcolor(15);
	rectangle(231,280,400,310);
	setfillstyle(1,5);
	bar(232,281,399,309);
	outtextxy(270,283,"4th Sem.");
	outtextxy(270,283,"4th Sem.");
	//5th Sem. Button
	setcolor(15);
	rectangle(231,320,400,350);
	setfillstyle(1,5);
	bar(232,321,399,349);
	outtextxy(270,320,"5th Sem.");
	outtextxy(270,320,"5th Sem.");
	//6th Sem Button
	setcolor(15);
	rectangle(231,360,400,390);
	setfillstyle(1,5);
	bar(232,361,399,389);
	outtextxy(270,360,"6th Sem.");
	outtextxy(270,360,"6th Sem.");
//	cleardevice();
	delay(250);
	mouse_semester_add_teacher();

}
// Mouse detection for select semester for add teacher
void mouse_semester_add_teacher()
{
   //initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
	while(1)//!kbhit())
      // while(!kbhit())
       {
		 o.x.bx=0;
		 show_mouse();
		 get_mouse();
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<200&&o.x.dx>160)
		 {
			//1st Sem. clicking
			sound(999);
			setcolor(15);
			rectangle(230,160,400,190);
			setfillstyle(1,14);
			bar(231,161,399,189);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(270,161,"1st Sem.");
			outtextxy(270,161,"1st Sem.");
			delay(250);
			nosound();
			//delay(1000);
		       //	cleardevice();
			select_semester_add_teacher();
		 }
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<230&&o.x.dx>200)
		{
			//2nd Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,200,400,230);
			setfillstyle(1,14);
			bar(232,201,399,229);
			setcolor(8);
			outtextxy(270,202,"2nd Sem.");
			outtextxy(270,202,"2nd Sem.");
			delay(100);
			nosound();

		       //	delay(1000);
			//cleardevice();
			select_semester_add_teacher();
		}
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<270&&o.x.dx>240)
		{
			//3rd Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,240,400,270);
			setfillstyle(1,14);
			bar(232,241,399,269);
			setcolor(8);
			outtextxy(270,243,"3rd Sem.");
			outtextxy(270,243,"3rd Sem.");
			delay(100);
			nosound();

		      //	delay(1000);
		    //	cleardevice();
			select_semester_add_teacher();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<310&&o.x.dx>280)
		{
			//4th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,280,400,310);
			setfillstyle(1,14);
			bar(232,281,399,309);
			setcolor(8);
			outtextxy(270,283,"4th Sem.");
			outtextxy(270,283,"4th Sem.");
			delay(100);
			nosound();

			//delay(1000);
			//cleardevice();
			select_semester_add_teacher();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<350&&o.x.dx>320)
		{
			//5th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,320,400,350);
			setfillstyle(1,14);
			bar(232,321,399,349);
			setcolor(8);
			outtextxy(270,320,"5th Sem.");
			outtextxy(270,320,"5th Sem.");
			delay(100);
			nosound();


		      ///	delay(1000);
		    //	cleardevice();
			select_semester_add_teacher();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<390&&o.x.dx>360)
		{
			//6th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,360,400,390);
			setfillstyle(1,14);
			bar(232,361,399,389);
			setcolor(8);
			outtextxy(270,360,"6th Sem.");
			outtextxy(270,360,"6th Sem.");
			delay(100);
			nosound();
		      //	delay(1000);
		    //	cleardevice();
			select_semester_add_teacher();
		}
		if(o.x.bx==1&&o.x.cx<150&&o.x.cx>127&&o.x.dx<310&&o.x.dx>230)
		{
			//Back Button  Clicking
			sound(999);
			setcolor(15);
			rectangle(121,230,150,310);
			setfillstyle(1,14);
			bar(122,231,149,309);
			setcolor(8);
			settextstyle(1,0,3);
			outtextxy(125,232,"B");
			outtextxy(125,246,"a");
			outtextxy(125,260,"c");
			outtextxy(125,277,"k");
			delay(100);
			nosound();
			cleardevice();
			admin_main();
		}
		if(o.x.bx==1&&o.x.cx<519&&o.x.cx>490&&o.x.dx<310&&o.x.dx>230)
		{
			//Exit Button  Clicking
			sound(999);
			setcolor(15);
			rectangle(490,231,519,309);
			setfillstyle(1,14);
			bar(491,232,518,308);
			setcolor(8);
			outtextxy(495,232,"E");
			outtextxy(495,246,"x");
			outtextxy(495,265,"i");
			outtextxy(495,281,"t");
			delay(250);
			nosound();
			cleardevice();
			exit_screen();
		}

	  }

}
// Make function for adding teacher details and their crosponding function







//Semester selection for remove teacheer
void select_semester_rem_teacher()
{
	cleardevice();
	outline();
	cn();
	/* outline */
	setcolor(15);
	rectangle(120,110,520,400);
	rectangle(121,111,520,400);
	rectangle(119,109,521,401);
	rectangle(121,111,521,152);
	setfillstyle(1,3);
	bar(122,112,519,151);
	setfillstyle(1,7);
	bar(122,153,519,399);
	setcolor(14);
	settextstyle(1,0,3);
	outtextxy(123,111,"Select Semester For Remove Teac..");
	outtextxy(123,111,"Select Semester For Remove Teac..");
	//Back Button
	setcolor(15);
	rectangle(121,230,150,310);
	setfillstyle(1,8);
	bar(122,231,149,309);
	settextstyle(1,0,3);
	outtextxy(125,232,"B");
	outtextxy(125,246,"a");
	outtextxy(125,260,"c");
	outtextxy(125,277,"k");
	//Exit Button
	setcolor(15);
	rectangle(490,231,519,309);
	setfillstyle(1,8);
	bar(491,232,518,308);
	setcolor(15);
	outtextxy(495,232,"E");
	outtextxy(495,246,"x");
	outtextxy(495,265,"i");
	outtextxy(495,281,"t");
	//1st sem. Button
	setcolor(15);
	rectangle(230,160,400,190);
	setfillstyle(1,5);
	bar(231,161,399,189);
	settextstyle(1,0,2);
	outtextxy(270,161,"1st Sem.");
	outtextxy(270,161,"1st Sem.");
	//2nd Sem. Button
	setcolor(15);
	rectangle(231,200,400,230);
	setfillstyle(1,5);
	bar(232,201,399,229);
	outtextxy(270,202,"2nd Sem.");
	outtextxy(270,202,"2nd Sem.");
	//3rd Sem. Button
	setcolor(15);
	rectangle(231,240,400,270);
	setfillstyle(1,5);
	bar(232,241,399,269);
	outtextxy(270,243,"3rd Sem.");
	outtextxy(270,243,"3rd Sem.");
	//4th Sem. Button
	setcolor(15);
	rectangle(231,280,400,310);
	setfillstyle(1,5);
	bar(232,281,399,309);
	outtextxy(270,283,"4th Sem.");
	outtextxy(270,283,"4th Sem.");
	//5th Sem. Button
	setcolor(15);
	rectangle(231,320,400,350);
	setfillstyle(1,5);
	bar(232,321,399,349);
	outtextxy(270,320,"5th Sem.");
	outtextxy(270,320,"5th Sem.");
	//6th Sem Button
	setcolor(15);
	rectangle(231,360,400,390);
	setfillstyle(1,5);
	bar(232,361,399,389);
	outtextxy(270,360,"6th Sem.");
	outtextxy(270,360,"6th Sem.");
//	cleardevice();
	delay(250);
	mouse_semester_rem_teacher();

}
//Mouse Detection for select semester for remove teacher
void mouse_semester_rem_teacher()
{
   //initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
	while(1)//!kbhit())
      // while(!kbhit())
       {
		 o.x.bx=0;
		 show_mouse();
		 get_mouse();
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<200&&o.x.dx>160)
		 {
			//1st Sem. clicking
			sound(999);
			setcolor(15);
			rectangle(230,160,400,190);
			setfillstyle(1,14);
			bar(231,161,399,189);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(270,161,"1st Sem.");
			outtextxy(270,161,"1st Sem.");
			delay(250);
			nosound();
			//delay(1000);
		       //	cleardevice();
			select_semester_rem_teacher();
		 }
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<230&&o.x.dx>200)
		{
			//2nd Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,200,400,230);
			setfillstyle(1,14);
			bar(232,201,399,229);
			setcolor(8);
			outtextxy(270,202,"2nd Sem.");
			outtextxy(270,202,"2nd Sem.");
			delay(100);
			nosound();

		       //	delay(1000);
			//cleardevice();
			select_semester_rem_teacher();
		}
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<270&&o.x.dx>240)
		{
			//3rd Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,240,400,270);
			setfillstyle(1,14);
			bar(232,241,399,269);
			setcolor(8);
			outtextxy(270,243,"3rd Sem.");
			outtextxy(270,243,"3rd Sem.");
			delay(100);
			nosound();

		      //	delay(1000);
		    //	cleardevice();
			select_semester_rem_teacher();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<310&&o.x.dx>280)
		{
			//4th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,280,400,310);
			setfillstyle(1,14);
			bar(232,281,399,309);
			setcolor(8);
			outtextxy(270,283,"4th Sem.");
			outtextxy(270,283,"4th Sem.");
			delay(100);
			nosound();

			//delay(1000);
			//cleardevice();
			select_semester_rem_teacher();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<350&&o.x.dx>320)
		{
			//5th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,320,400,350);
			setfillstyle(1,14);
			bar(232,321,399,349);
			setcolor(8);
			outtextxy(270,320,"5th Sem.");
			outtextxy(270,320,"5th Sem.");
			delay(100);
			nosound();


		      ///	delay(1000);
		    //	cleardevice();
			select_semester_rem_teacher();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<390&&o.x.dx>360)
		{
			//6th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,360,400,390);
			setfillstyle(1,14);
			bar(232,361,399,389);
			setcolor(8);
			outtextxy(270,360,"6th Sem.");
			outtextxy(270,360,"6th Sem.");
			delay(100);
			nosound();
		      //	delay(1000);
		    //	cleardevice();
			select_semester_rem_teacher();
		}
		if(o.x.bx==1&&o.x.cx<150&&o.x.cx>127&&o.x.dx<310&&o.x.dx>230)
		{
			//Back Button  Clicking
			sound(999);
			setcolor(15);
			rectangle(121,230,150,310);
			setfillstyle(1,14);
			bar(122,231,149,309);
			setcolor(8);
			settextstyle(1,0,3);
			outtextxy(125,232,"B");
			outtextxy(125,246,"a");
			outtextxy(125,260,"c");
			outtextxy(125,277,"k");
			delay(100);
			nosound();
			cleardevice();
			admin_main();
		}
		if(o.x.bx==1&&o.x.cx<519&&o.x.cx>490&&o.x.dx<310&&o.x.dx>230)
		{
			//Exit Button  Clicking
			sound(999);
			setcolor(15);
			rectangle(490,231,519,309);
			setfillstyle(1,14);
			bar(491,232,518,308);
			setcolor(8);
			outtextxy(495,232,"E");
			outtextxy(495,246,"x");
			outtextxy(495,265,"i");
			outtextxy(495,281,"t");
			delay(250);
			nosound();
			cleardevice();
			exit_screen();
		}

	  }


}
//Make Functoin for Removing tteacher For Each Semester
//and their crosponding   function






//Semestyer Selection For View Teacher
void select_semester_view_teacher()
{     	cleardevice();
	outline();
	cn();
	/* outline */
	setcolor(15);
	rectangle(120,110,520,400);
	rectangle(121,111,520,400);
	rectangle(119,109,521,401);
	rectangle(121,111,521,152);
	setfillstyle(1,3);
	bar(122,112,519,151);
	setfillstyle(1,7);
	bar(122,153,519,399);
	setcolor(14);
	settextstyle(1,0,3);
	outtextxy(123,111,"Select Semester For View Teacher");
	outtextxy(123,111,"Select Semester For View Teacher");
	//Back Button
	setcolor(15);
	rectangle(121,230,150,310);
	setfillstyle(1,8);
	bar(122,231,149,309);
	settextstyle(1,0,3);
	outtextxy(125,232,"B");
	outtextxy(125,246,"a");
	outtextxy(125,260,"c");
	outtextxy(125,277,"k");
	//Exit Button
	setcolor(15);
	rectangle(490,231,519,309);
	setfillstyle(1,8);
	bar(491,232,518,308);
	setcolor(15);
	outtextxy(495,232,"E");
	outtextxy(495,246,"x");
	outtextxy(495,265,"i");
	outtextxy(495,281,"t");
	//1st sem. Button
	setcolor(15);
	rectangle(230,160,400,190);
	setfillstyle(1,5);
	bar(231,161,399,189);
	settextstyle(1,0,2);
	outtextxy(270,161,"1st Sem.");
	outtextxy(270,161,"1st Sem.");
	//2nd Sem. Button
	setcolor(15);
	rectangle(231,200,400,230);
	setfillstyle(1,5);
	bar(232,201,399,229);
	outtextxy(270,202,"2nd Sem.");
	outtextxy(270,202,"2nd Sem.");
	//3rd Sem. Button
	setcolor(15);
	rectangle(231,240,400,270);
	setfillstyle(1,5);
	bar(232,241,399,269);
	outtextxy(270,243,"3rd Sem.");
	outtextxy(270,243,"3rd Sem.");
	//4th Sem. Button
	setcolor(15);
	rectangle(231,280,400,310);
	setfillstyle(1,5);
	bar(232,281,399,309);
	outtextxy(270,283,"4th Sem.");
	outtextxy(270,283,"4th Sem.");
	//5th Sem. Button
	setcolor(15);
	rectangle(231,320,400,350);
	setfillstyle(1,5);
	bar(232,321,399,349);
	outtextxy(270,320,"5th Sem.");
	outtextxy(270,320,"5th Sem.");
	//6th Sem Button
	setcolor(15);
	rectangle(231,360,400,390);
	setfillstyle(1,5);
	bar(232,361,399,389);
	outtextxy(270,360,"6th Sem.");
	outtextxy(270,360,"6th Sem.");
//	cleardevice();
	delay(250);
	mouse_semester_view_teacher();


}
//mouse Detection for view teacher for each semester
void mouse_semester_view_teacher()
{
   //initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
	while(1)//!kbhit())
      // while(!kbhit())
       {
		 o.x.bx=0;
		 show_mouse();
		 get_mouse();
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<200&&o.x.dx>160)
		 {
			//1st Sem. clicking
			sound(999);
			setcolor(15);
			rectangle(230,160,400,190);
			setfillstyle(1,14);
			bar(231,161,399,189);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(270,161,"1st Sem.");
			outtextxy(270,161,"1st Sem.");
			delay(250);
			nosound();
			//delay(1000);
		       //	cleardevice();
			select_semester_view_teacher();
		 }
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<230&&o.x.dx>200)
		{
			//2nd Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,200,400,230);
			setfillstyle(1,14);
			bar(232,201,399,229);
			setcolor(8);
			outtextxy(270,202,"2nd Sem.");
			outtextxy(270,202,"2nd Sem.");
			delay(100);
			nosound();

		       //	delay(1000);
			//cleardevice();
			select_semester_view_teacher();
		}
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<270&&o.x.dx>240)
		{
			//3rd Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,240,400,270);
			setfillstyle(1,14);
			bar(232,241,399,269);
			setcolor(8);
			outtextxy(270,243,"3rd Sem.");
			outtextxy(270,243,"3rd Sem.");
			delay(100);
			nosound();

		      //	delay(1000);
		    //	cleardevice();
			select_semester_view_teacher();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<310&&o.x.dx>280)
		{
			//4th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,280,400,310);
			setfillstyle(1,14);
			bar(232,281,399,309);
			setcolor(8);
			outtextxy(270,283,"4th Sem.");
			outtextxy(270,283,"4th Sem.");
			delay(100);
			nosound();

			//delay(1000);
			//cleardevice();
			select_semester_view_teacher();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<350&&o.x.dx>320)
		{
			//5th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,320,400,350);
			setfillstyle(1,14);
			bar(232,321,399,349);
			setcolor(8);
			outtextxy(270,320,"5th Sem.");
			outtextxy(270,320,"5th Sem.");
			delay(100);
			nosound();


		      ///	delay(1000);
		    //	cleardevice();
			select_semester_view_teacher();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<390&&o.x.dx>360)
		{
			//6th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,360,400,390);
			setfillstyle(1,14);
			bar(232,361,399,389);
			setcolor(8);
			outtextxy(270,360,"6th Sem.");
			outtextxy(270,360,"6th Sem.");
			delay(100);
			nosound();
		      //	delay(1000);
		    //	cleardevice();
			select_semester_view_teacher();
		}
		if(o.x.bx==1&&o.x.cx<150&&o.x.cx>127&&o.x.dx<310&&o.x.dx>230)
		{
			//Back Button  Clicking
			sound(999);
			setcolor(15);
			rectangle(121,230,150,310);
			setfillstyle(1,14);
			bar(122,231,149,309);
			setcolor(8);
			settextstyle(1,0,3);
			outtextxy(125,232,"B");
			outtextxy(125,246,"a");
			outtextxy(125,260,"c");
			outtextxy(125,277,"k");
			delay(100);
			nosound();
			cleardevice();
			admin_main();
		}
		if(o.x.bx==1&&o.x.cx<519&&o.x.cx>490&&o.x.dx<310&&o.x.dx>230)
		{
			//Exit Button  Clicking
			sound(999);
			setcolor(15);
			rectangle(490,231,519,309);
			setfillstyle(1,14);
			bar(491,232,518,308);
			setcolor(8);
			outtextxy(495,232,"E");
			outtextxy(495,246,"x");
			outtextxy(495,265,"i");
			outtextxy(495,281,"t");
			delay(250);
			nosound();
			cleardevice();
			exit_screen();
		}

	  }

}
//*******************************************************************
//Notes Menu Mouse Detection
void notes_menu_mouse()
{
	//initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
	while(1)//!kbhit())
      // while(!kbhit())
      {
		 o.x.bx=0;
		 show_mouse();
		 get_mouse();
	 if(o.x.bx==1&&o.x.cx<558&&o.x.cx>400&&o.x.dx<58&&o.x.dx>27)
		{
			//Add Notes   clicking
			sound(999);
			setfillstyle(1,14);
			bar(401,28,558,58);
			setcolor(8);
			rectangle(400,27,558,58);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(415,30,"Add Notes...");
			delay(250);
			nosound();
			cleardevice();
		       add_notes_main_screen();
		}
		 if(o.x.bx==1&&o.x.cx<558&&o.x.cx>400&&o.x.dx<88&&o.x.dx>58)
		{
			//Delete Notes Clicking
			sound(999);
			setfillstyle(1,14);
			bar(402,88,557,58);
			setlinestyle(1,0,15);
			setcolor(8);
			rectangle(401,87,558,58);
			setcolor(8);
			outtextxy(415,60,"Delete Notes...");
			delay(250);
			nosound();
			cleardevice();
			 delete_notes_main_screen();
		}
		 if(o.x.bx==1&&o.x.cx<558&&o.x.cx>400&&o.x.dx<115&&o.x.dx>85)
		{
			//view Notes Clicking
			sound(999);
			setfillstyle(1,14);
			bar(401,85,557,115);
			setlinestyle(1,0,15);
			setcolor(8);
			rectangle(400,85,558,115);
			setcolor(8);
			outtextxy(415,90,"View Notes...");
			delay(250);
			nosound();
			view_notes_main_screen();


		}
	  }
}

//Add Notes Main Screen
void add_notes_main_screen()
{
	 cleardevice();
	//Center name
	setcolor(15);
	line(2,444,669,444);
	setfillstyle(1,9);
	bar(2,445,669,480);
	settextstyle(1,0,4);
	setcolor(14);
	settextstyle(1,0,4);
	setcolor(14);
	outtextxy(120,441," DEEPAK COMPUTER CENTER ");
	outtextxy(121,441," DEEPAK COMPUTER CENTER ");
	outtextxy(122,441," DEEPAK COMPUTER CENTER ");
	 // Add Notes Messege
	 setfillstyle(1,10);
	 bar(1,1,670,25);
	 setfillstyle(1,7);
	 bar(250,0,420,25);
	 setlinestyle(1,0,5);
	 rectangle(250,0,420,25);
	 setcolor(9);
	settextstyle(1,0,2);
	outtextxy(285,0,"Add Note's.");
	//Ribbon
	setcolor(14);
	//Top line
	line(0,0,670,0);
	line(1,0,670,0);
	//Secoand line
	line(0,26,670,26);
	line(0,27,670,27);
	//Third line
	line(0,52,670,52);
	line(0,53,670,53);
	setfillstyle(1,7);
	bar(0,28,670,51);
	//left line
	line(0,0,0,640);
	line(1,0,1,640);
	//Right line
	line(639,0,639,640);
	line(638,0,638,640);
	// Tabs
	//1st Sem.
	setcolor(6);
       //	rectangle(10,29,90,51);
	setcolor(9);
	settextstyle(1,0,1);
	outtextxy(12,29,"1st.Sem.");
	//2nd Sem.
	setcolor(3);
       //	rectangle(120,29,213,51);
	setcolor(9);
	settextstyle(1,0,1);
	outtextxy(127,29,"2nd.Sem.");
	//3rd Sem.
	setcolor(5);
       //	rectangle(235,29,320,51);
	setcolor(9);
	settextstyle(1,0,1);
	outtextxy(238,29,"3rd.Sem.");
	//4th Sem.
	setcolor(4);
       //	rectangle(340,29,425,51);
	setcolor(9);
	settextstyle(1,0,1);
	outtextxy(342,29,"4th.Sem.");
	//5th Sem
	setcolor(15);
       //	rectangle(440,29,525,51);
	setcolor(9);
	settextstyle(1,0,1);
	outtextxy(443,29,"5th.Sem.");
	//6th Sem.
	setcolor(5);
       //	rectangle(542,29,628,51);
	setcolor(9);
	settextstyle(1,0,1);
	outtextxy(544,29,"6th.Sem.");
       //	setcolor(15);
	//Back
       //	rectangle(2,1,70,25);
	setcolor(9);
	settextstyle(1,0,2);
	outtextxy(10,0,"Back");

	//Exit
       //	rectangle(570,1,638,25);
	setcolor(9);
	settextstyle(1,0,2);
	outtextxy(585,0,"Exit");
	add_notes_main_mouse();

}
// Notes Main Screen Mouse Detection
void add_notes_main_mouse()
{
	//initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
   //	while(!kbhit())
   while(1)
      {
		  o.x.bx=0;
		 show_mouse();
		 get_mouse();
	       if(o.x.bx==1&&o.x.cx<70&&o.x.cx>2&&o.x.dx<25&&o.x.dx>1)
	       {
			//Back
			sound(999);
			setfillstyle(1,14);
			bar(2,1,70,25);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(10,0,"Back");
			delay(200);
			nosound();
			cleardevice();
			admin_main();
		}
		if(o.x.bx==1&&o.x.cx<638&&o.x.cx>570&&o.x.dx<25&&o.x.dx>1)
		{
			//Exit
			sound(999);
			setlinestyle(0,0,2);
			rectangle(569,1,639,25);
			setfillstyle(1,14);
			bar(570,1,638,25);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(585,0,"Exit");
			nosound();
			delay(200);
			cleardevice();
			exit_screen();
		}
		if(o.x.bx==1&&o.x.cx<90&&o.x.cx>10&&o.x.dx<51&&o.x.dx>29)
		{
			//1st Sem Clicking
			sound(999);
			setcolor(9);
			setlinestyle(0,0,2);
			rectangle(9,28,91,52);
			setfillstyle(1,14);
			bar(10,29,90,51);
			setcolor(9);
			settextstyle(1,0,1);
			outtextxy(12,29,"1st.Sem.");
			nosound();
			delay(200);
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(9,53,91,235);
			setfillstyle(1,3);
			bar(10,55,90,234);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(28,56,"101");
			setcolor(15);
			line(27,80,90,80);
			setcolor(14);
			outtextxy(28,82,"102");
			setcolor(15);
			line(27,110,90,110);
			setcolor(14);
			outtextxy(28,112,"103");
			setcolor(15);
			line(27,140,90,140);
			setcolor(14);
			outtextxy(28,142,"104");
			setcolor(15);
			line(27,170,90,170);
			setcolor(14);
			outtextxy(28,173,"105");
			setcolor(15);
			line(27,200,90,200);
			setcolor(14);;
			outtextxy(28,203,"106");
		       delay(250);

		       mouse_add_notes_1st_sem();

		}
		if(o.x.bx==1&&o.x.cx<213&&o.x.cx>120&&o.x.dx<51&&o.x.dx>29)
		{
			//2nd Sem Clicking
			sound(999);
			setcolor(9);
			setlinestyle(0,0,2);
			rectangle(119,28,214,52);
			setfillstyle(1,14);
			bar(120,29,213,51);
			setcolor(9);
			settextstyle(1,0,1);
			outtextxy(127,29,"2nd.Sem.");
			nosound();
			delay(200);
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(119,55,214,235);
			setfillstyle(1,3);
			bar(120,56,213,234);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(150,56,"201");
			setcolor(15);
			line(149,82,213,82);
			setcolor(14);
			outtextxy(150,82,"202");
			setcolor(15);
			line(149,110,213,110);
			setcolor(14);
			outtextxy(150,112,"203");
			setcolor(15);
			line(149,140,213,140);
			setcolor(14);
			outtextxy(150,142,"204");
			setcolor(15);
			line(149,170,213,170);
			setcolor(14);
			outtextxy(150,173,"205");
			setcolor(15);
			line(149,200,213,200);
			setcolor(14);
			outtextxy(150,203,"206");
			delay(1500);
			mouse_add_notes_2nd_sem();
		       //	add_notes_main_screen();


		}
		if(o.x.bx==1&&o.x.cx<320&&o.x.cx>235&&o.x.dx<51&&o.x.dx>29)
		{
			//3rd Sem Clicking
			sound(999);
			setcolor(9);
			setlinestyle(0,0,2);
			rectangle(234,28,321,52);
			setfillstyle(1,14);
			bar(235,29,320,51);
			setcolor(9);
			settextstyle(1,0,1);
			outtextxy(238,29,"3rd.Sem.");
			nosound();
			delay(200);
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(234,55,321,235);
			setfillstyle(1,3);
			bar(235,56,320,234);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(262,56,"301");
			setcolor(15);
			line(261,82,320,82);
			setcolor(14);
			outtextxy(262,82,"302");
			setcolor(15);
			line(261,110,320,110);
			setcolor(14);
			outtextxy(262,112,"303");
			setcolor(15);
			line(261,140,320,140);
			setcolor(14);
			outtextxy(262,142,"304");
			setcolor(15);
			line(261,170,320,170);
			setcolor(14);
			outtextxy(262,173,"305");
			setcolor(15);
			line(261,200,320,200);
			setcolor(14);
			outtextxy(262,203,"306");
			delay(100);
		     //	cleardevice();
		    //	add_notes_main_screen();
			 mouse_add_notes_3rd_sem();



		}
		if(o.x.bx==1&&o.x.cx<425&&o.x.cx>340&&o.x.dx<51&&o.x.dx>29)
		{
			//4th Sem Clicking
			sound(999);
			setcolor(9);
			setlinestyle(0,0,2);
			rectangle(339,28,426,52);
			setfillstyle(1,14);
			bar(340,29,425,51);
			setcolor(9);
			settextstyle(1,0,1);
			outtextxy(342,29,"4th.Sem.");
			nosound();
			delay(200);
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(339,55,426,235);
			setfillstyle(1,3);
			bar(340,56,425,234);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(363,56,"401");
			setcolor(15);
			line(361,82,425,82);
			setcolor(14);
			outtextxy(363,82,"402");
			setcolor(15);
			line(361,110,425,110);
			setcolor(14);
			outtextxy(363,112,"403");
			setcolor(15);
			line(361,140,425,140);
			setcolor(14);
			outtextxy(363,142,"404");
			setcolor(15);
			line(361,170,425,170);
			setcolor(14);
			outtextxy(363,173,"405");
			setcolor(15);
			line(361,200,425,200);
			setcolor(14);
			outtextxy(363,203,"406");
			delay(1500);
		 //	cleardevice();
		   //	add_notes_main_screen();
			mouse_add_notes_4th_sem();


		}
		if(o.x.bx==1&&o.x.cx<525&&o.x.cx>440&&o.x.dx<51&&o.x.dx>29)
		{
			//5th Sem Clicking
			sound(999);
			setcolor(9);
			setlinestyle(0,0,2);
			rectangle(439,28,526,52);
			setfillstyle(1,14);
			bar(440,29,525,51);
			setcolor(9);
			settextstyle(1,0,1);
			outtextxy(443,29,"5th.Sem.");
			nosound();
			delay(200);
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(439,55,526,235);
			setfillstyle(1,3);
			bar(440,56,525,234);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(466,56,"501");
			setcolor(15);
			line(464,82,525,82);
			setcolor(14);
			outtextxy(466,82,"502");
			setcolor(15);
			line(464,110,525,110);
			setcolor(14);
			outtextxy(466,112,"503");
			setcolor(15);
			line(464,140,525,140);
			setcolor(14);
			outtextxy(466,142,"504");
			setcolor(15);
			line(464,170,525,170);
			setcolor(14);
			outtextxy(466,173,"505");
			setcolor(15);
			line(464,200,525,200);
			setcolor(14);
			outtextxy(466,203,"506");
			delay(200);
			//cleardevice();
			//add_notes_main_screen();
			mouse_add_notes_5th_sem();




		}
		if(o.x.bx==1&&o.x.cx<628&&o.x.cx>542&&o.x.dx<51&&o.x.dx>29)
		{
		       //	cleardevice();
		     //	add_notes_main_screen();
			//6th Sem Clicking
			sound(999);
			setcolor(9);
			setlinestyle(0,0,2);
			rectangle(541,28,629,52);
			setfillstyle(1,14);
			bar(542,29,628,51);
			setcolor(9);
			settextstyle(1,0,1);
			outtextxy(544,29,"6th.Sem.");
			nosound();
			delay(200);
		     //	cleardevice();
		      // add_notes_main_screen();
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(541,55,629,235);
			setfillstyle(1,3);
			bar(542,56,628,234);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(569,56,"601");
			setcolor(15);
			line(568,82,628,82);
			setcolor(14);
			outtextxy(569,82,"602");
			setcolor(15);
			line(568,110,628,110);
			setcolor(14);
			outtextxy(569,112,"603");
			setcolor(15);
			line(568,140,628,140);
			setcolor(14);
			outtextxy(569,142,"604");
			setcolor(15);
			line(568,170,628,170);
			setcolor(14);
			outtextxy(569,173,"605");
			setcolor(15);
			line(568,200,628,200);
			setcolor(14);
			outtextxy(569,203,"606");
			delay(200);
		       //	cleardevice();
		    //	add_notes_main_screen();
			mouse_add_notes_6th_sem();



		}
      }

}

//Moouse Detection For 1st  Sem For Adding Notes
void  mouse_add_notes_1st_sem()
{
       //initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
   //	while(!kbhit())
   while(1)
      {
		  o.x.bx=0;
		 show_mouse();
		 get_mouse();
		if(o.x.bx==1&&o.x.cx<91&&o.x.cx>9&&o.x.dx<83&&o.x.dx>53)
		{
			//101
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(9,53,91,83);
			setfillstyle(1,14);
			bar(10,54,90,82);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(28,56,"101");
			delay(250);
			nosound();
			delay(100);
		  //	add_notes_main_screen();
		  write_notes_1st_sem_101_secrrn();
		}
		if(o.x.bx==1&&o.x.cx<91&&o.x.cx>9&&o.x.dx<110&&o.x.dx>80)
		{
			//102
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(9,80,91,110);
			setfillstyle(1,14);
			bar(10,81,90,109);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(28,82,"102");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<91&&o.x.cx>9&&o.x.dx<140&&o.x.dx>110)
		{
			//103
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(9,110,91,140);
			setfillstyle(1,14);
			bar(10,111,90,139);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(28,112,"103");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<91&&o.x.cx>9&&o.x.dx<170&&o.x.dx>140)
		{
			//104
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(9,140,91,170);
			setfillstyle(1,14);
			bar(10,141,90,169);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(28,142,"104");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
	      if(o.x.bx==1&&o.x.cx<91&&o.x.cx>9&&o.x.dx<200&&o.x.dx>170)
		{
			//105
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(9,170,91,200);
			setfillstyle(1,14);
			bar(10,171,90,199);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(28,173,"105");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<91&&o.x.cx>9&&o.x.dx<235&&o.x.dx>200)
		{
			//106
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(9,200,91,235);
			setfillstyle(1,14);
			bar(10,201,90,234);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(28,203,"106");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}

      }
}

//Mouse Detection For 2nd  Sem For Adding Notes
void mouse_add_notes_2nd_sem()
{
	   //initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
   //	while(!kbhit())
   while(1)
      {
		  o.x.bx=0;
		 show_mouse();
		 get_mouse();
		if(o.x.bx==1&&o.x.cx<214&&o.x.cx>119&&o.x.dx<83&&o.x.dx>53)
		{
			//201
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(119,53,214,83);
			setfillstyle(1,14);
			bar(120,54,213,82);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(150,56,"201");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<214&&o.x.cx>119&&o.x.dx<110&&o.x.dx>80)
		{
			//202
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(119,80,214,110);
			setfillstyle(1,14);
			bar(120,81,213,109);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(150,82,"202");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<214&&o.x.cx>119&&o.x.dx<140&&o.x.dx>110)
		{
			//203
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(119,110,214,140);
			setfillstyle(1,14);
			bar(120,111,213,139);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(150,112,"203");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<214&&o.x.cx>119&&o.x.dx<170&&o.x.dx>140)
		{
			//204
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(119,140,214,170);
			setfillstyle(1,14);
			bar(120,141,213,169);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(150,142,"204");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
	      if(o.x.bx==1&&o.x.cx<214&&o.x.cx>119&&o.x.dx<200&&o.x.dx>170)
		{
			//205
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(119,170,214,200);
			setfillstyle(1,14);
			bar(120,171,213,199);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(150,173,"205");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<214&&o.x.cx>119&&o.x.dx<235&&o.x.dx>200)
		{
			//206
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(119,200,214,235);
			setfillstyle(1,14);
			bar(120,201,213,234);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(150,203,"206");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}

      }


}
//Mouse Detection For 3rd  Sem For Adding Notes
void mouse_add_notes_3rd_sem()
{
  //initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
   //	while(!kbhit())
   while(1)
      {
		  o.x.bx=0;
		 show_mouse();
		 get_mouse();
		if(o.x.bx==1&&o.x.cx<321&&o.x.cx>234&&o.x.dx<83&&o.x.dx>53)
		{
			//301
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(234,53,321,83);
			setfillstyle(1,14);
			bar(235,54,320,82);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(262,56,"301");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<321&&o.x.cx>234&&o.x.dx<110&&o.x.dx>80)
		{
			//302
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(234,80,321,110);
			setfillstyle(1,14);
			bar(235,81,320,109);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(262,82,"302");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<321&&o.x.cx>234&&o.x.dx<140&&o.x.dx>110)
		{
			//303
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(234,110,321,140);
			setfillstyle(1,14);
			bar(235,111,320,139);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(262,112,"303");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<321&&o.x.cx>234&&o.x.dx<170&&o.x.dx>140)
		{
			//304
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(234,140,321,170);
			setfillstyle(1,14);
			bar(235,141,320,169);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(262,142,"304");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
	      if(o.x.bx==1&&o.x.cx<321&&o.x.cx>234&&o.x.dx<200&&o.x.dx>170)
		{
			//305
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(234,170,321,200);
			setfillstyle(1,14);
			bar(235,171,320,199);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(262,173,"305");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<321&&o.x.cx>234&&o.x.dx<235&&o.x.dx>200)
		{
			//306
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(234,200,321,235);
			setfillstyle(1,14);
			bar(235,201,320,234);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(262,203,"306");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}

      }


}
//Mouse Detection For 4th  Sem For Adding Notes
void mouse_add_notes_4th_sem()
{
      //initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
   //	while(!kbhit())
	while(1)
      {
		  o.x.bx=0;
		 show_mouse();
		 get_mouse();
		if(o.x.bx==1&&o.x.cx<426&&o.x.cx>339&&o.x.dx<83&&o.x.dx>53)
		{
			//401
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(339,53,426,83);
			setfillstyle(1,14);
			bar(340,54,425,82);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(363,56,"401");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<426&&o.x.cx>339&&o.x.dx<110&&o.x.dx>80)
		{
			//402
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(339,80,426,110);
			setfillstyle(1,14);
			bar(340,81,425,109);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(363,82,"402");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<426&&o.x.cx>339&&o.x.dx<140&&o.x.dx>110)
		{
			//403
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(339,110,426,140);
			setfillstyle(1,14);
			bar(340,111,425,139);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(363,112,"403");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<426&&o.x.cx>339&&o.x.dx<170&&o.x.dx>140)
		{
			//404
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(339,140,426,170);
			setfillstyle(1,14);
			bar(340,141,425,169);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(363,142,"404");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
	      if(o.x.bx==1&&o.x.cx<426&&o.x.cx>339&&o.x.dx<200&&o.x.dx>170)
		{
			//405
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(339,170,426,200);
			setfillstyle(1,14);
			bar(340,171,425,199);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(363,173,"405");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<426&&o.x.cx>339&&o.x.dx<235&&o.x.dx>200)
		{
			//406
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(339,200,426,235);
			setfillstyle(1,14);
			bar(340,201,425,234);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(363,203,"406");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}

      }



}
//Mouse Detection For 5th  Sem For Adding Notes
void mouse_add_notes_5th_sem()
{
	  //initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
   //	while(!kbhit())
	while(1)
      {
		  o.x.bx=0;
		 show_mouse();
		 get_mouse();
		if(o.x.bx==1&&o.x.cx<526&&o.x.cx>439&&o.x.dx<83&&o.x.dx>53)
		{
			//501
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(439,53,526,83);
			setfillstyle(1,14);
			bar(440,54,525,82);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(466,56,"501");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<526&&o.x.cx>439&&o.x.dx<110&&o.x.dx>80)
		{
			//502
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(439,80,526,110);
			setfillstyle(1,14);
			bar(440,81,525,109);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(466,82,"502");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<526&&o.x.cx>439&&o.x.dx<140&&o.x.dx>110)
		{
			//503
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(439,110,526,140);
			setfillstyle(1,14);
			bar(440,111,525,139);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(466,112,"503");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<526&&o.x.cx>439&&o.x.dx<170&&o.x.dx>140)
		{
			//504
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(439,140,526,170);
			setfillstyle(1,14);
			bar(440,141,525,169);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(466,142,"504");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
	      if(o.x.bx==1&&o.x.cx<526&&o.x.cx>439&&o.x.dx<200&&o.x.dx>170)
		{
			//505
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(439,170,526,200);
			setfillstyle(1,14);
			bar(440,171,525,199);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(466,173,"505");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<526&&o.x.cx>439&&o.x.dx<235&&o.x.dx>200)
		{
			//506
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(439,200,526,235);
			setfillstyle(1,14);
			bar(440,201,525,234);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(466,203,"506");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}

      }


}
//Mouse Detection For 6th  Sem For Adding Notes
void mouse_add_notes_6th_sem()
{
	  //initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
   //	while(!kbhit())
	while(1)
      {
		  o.x.bx=0;
		 show_mouse();
		 get_mouse();
		if(o.x.bx==1&&o.x.cx<629&&o.x.cx>541&&o.x.dx<83&&o.x.dx>53)
		{
			//601
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(541,53,629,83);
			setfillstyle(1,14);
			bar(542,54,628,82);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(569,56,"601");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<629&&o.x.cx>541&&o.x.dx<110&&o.x.dx>80)
		{
			//602
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(541,80,629,110);
			setfillstyle(1,14);
			bar(542,81,628,109);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(569,82,"602");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<629&&o.x.cx>541&&o.x.dx<140&&o.x.dx>110)
		{
			//603
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(541,110,629,140);
			setfillstyle(1,14);
			bar(542,111,628,139);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(569,112,"603");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<629&&o.x.cx>541&&o.x.dx<170&&o.x.dx>140)
		{
			//604
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(541,140,629,170);
			setfillstyle(1,14);
			bar(542,141,628,169);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(569,142,"604");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
	      if(o.x.bx==1&&o.x.cx<629&&o.x.cx>541&&o.x.dx<200&&o.x.dx>170)
		{
			//605
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(541,170,629,200);
			setfillstyle(1,14);
			bar(542,171,628,199);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(569,173,"605");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<629&&o.x.cx>541&&o.x.dx<235&&o.x.dx>200)
		{
			//606
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(541,200,629,235);
			setfillstyle(1,14);
			bar(542,201,628,234);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(569,203,"606");
			delay(250);
			nosound();
			delay(100);
			add_notes_main_screen();
		}

      }


}
//Add Notes (writing) Sereen....
void  write_notes_1st_sem_101_secrrn()
{
	 cleardevice();
	//Center name
	setcolor(15);
	line(2,444,669,444);
	setfillstyle(1,9);
	bar(2,445,669,480);
	settextstyle(1,0,4);
	setcolor(14);
	settextstyle(1,0,4);
	setcolor(14);
	outtextxy(120,441," DEEPAK COMPUTER CENTER ");
	outtextxy(121,441," DEEPAK COMPUTER CENTER ");
	outtextxy(122,441," DEEPAK COMPUTER CENTER ");
       // Tabs
       //	setcolor(10);
	//Back
   //	rectangle(1,446,70,475);
	setcolor(15);
	settextstyle(1,0,2);
	outtextxy(10,446,"Back");
	//Exit
       //	rectangle(580,446,667,475);
	setcolor(15);
	settextstyle(1,0,2);
	outtextxy(595,446,"Exit");

	 // Add Notes Messege
	 setcolor(4);
	 setfillstyle(1,10);
	 bar(1,1,670,25);
	 setfillstyle(1,7);
	 bar(241,0,429,25);
	 setlinestyle(1,0,5);
	 rectangle(240,1,430,25);
	setcolor(9);
	settextstyle(1,0,2);
	outtextxy(248,0,"Add Note's. - 101");
	//Ribbon
	setcolor(14);
	//Top line
	line(0,0,670,0);
	line(1,0,670,0);
	//Secoand line
	line(0,26,670,26);
	line(0,27,670,27);
	//left line
	line(0,0,0,640);
	line(1,0,1,640);
	//Right line
	line(639,0,639,640);
	line(638,0,638,640);
	//initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
   //	while(!kbhit())
   while(1)
      {
		  o.x.bx=0;
		 show_mouse();
		 get_mouse();
	       if(o.x.bx==1&&o.x.cx<70&&o.x.cx>2&&o.x.dx<475&&o.x.dx>446)
	       {
			//Back
			sound(999);
			setfillstyle(1,14);
			bar(2,447,69,474);
			setcolor(9);
			settextstyle(1,0,2);
			outtextxy(10,446,"Back");
			delay(200);
			nosound();
			cleardevice();
		       //	admin_main();
			add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<668&&o.x.cx>580&&o.x.dx<475&&o.x.dx>446)
		{
			//Exit
			sound(999);
			setlinestyle(0,0,2);
			rectangle(580,446,667,475);
			setfillstyle(1,14);
			bar(581,447,666,474);
			setcolor(9);
			settextstyle(1,0,2);
			outtextxy(595,446,"Exit");
			nosound();
			delay(200);
			cleardevice();
			exit_screen();
		}

	}
}




// above functoins are add notes for each semeter

// iooncomplete

//************************************************************************
//Delete Notes main screen for deleating notes for each semester
// and all functions
void delete_notes_main_screen()
{
	 cleardevice();
	//Center name
	setcolor(15);
	line(2,444,669,444);
	setfillstyle(1,9);
	bar(2,445,669,480);
	settextstyle(1,0,4);
	setcolor(14);
	settextstyle(1,0,4);
	setcolor(14);
	outtextxy(120,441," DEEPAK COMPUTER CENTER ");
	outtextxy(121,441," DEEPAK COMPUTER CENTER ");
	outtextxy(122,441," DEEPAK COMPUTER CENTER ");
	 // Add Notes Messege
	 setfillstyle(1,10);
	 bar(1,1,670,25);
	 setfillstyle(1,7);
	 bar(250,0,420,25);
	 setlinestyle(1,0,5);
	 rectangle(250,0,420,25);
	 setcolor(9);
	settextstyle(1,0,2);
	outtextxy(275,0,"Delete Note's.");
	//Ribbon
	setcolor(14);
	//Top line
	line(0,0,670,0);
	line(1,0,670,0);
	//Secoand line
	line(0,26,670,26);
	line(0,27,670,27);
	//Third line
	line(0,52,670,52);
	line(0,53,670,53);
	setfillstyle(1,7);
	bar(0,28,670,51);
	//left line
	line(0,0,0,640);
	line(1,0,1,640);
	//Right line
	line(639,0,639,640);
	line(638,0,638,640);
	// Tabs
	//1st Sem.
	setcolor(6);
       //	rectangle(10,29,90,51);
	setcolor(9);
	settextstyle(1,0,1);
	outtextxy(12,29,"1st.Sem.");
	//2nd Sem.
	setcolor(3);
       //	rectangle(120,29,213,51);
	setcolor(9);
	settextstyle(1,0,1);
	outtextxy(127,29,"2nd.Sem.");
	//3rd Sem.
	setcolor(5);
       //	rectangle(235,29,320,51);
	setcolor(9);
	settextstyle(1,0,1);
	outtextxy(238,29,"3rd.Sem.");
	//4th Sem.
	setcolor(4);
       //	rectangle(340,29,425,51);
	setcolor(9);
	settextstyle(1,0,1);
	outtextxy(342,29,"4th.Sem.");
	//5th Sem
	setcolor(15);
       //	rectangle(440,29,525,51);
	setcolor(9);
	settextstyle(1,0,1);
	outtextxy(443,29,"5th.Sem.");
	//6th Sem.
	setcolor(5);
       //	rectangle(542,29,628,51);
	setcolor(9);
	settextstyle(1,0,1);
	outtextxy(544,29,"6th.Sem.");
       //	setcolor(15);
	//Back
       //	rectangle(2,1,70,25);
	setcolor(9);
	settextstyle(1,0,2);
	outtextxy(10,0,"Back");

	//Exit
       //	rectangle(570,1,638,25);
	setcolor(9);
	settextstyle(1,0,2);
	outtextxy(585,0,"Exit");
	mouse_delete_notes_main_screen();

}
// Mouse Detection For Delete Notes Main Screen
void mouse_delete_notes_main_screen()
{
	//initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
   //	while(!kbhit())
   while(1)
      {
		  o.x.bx=0;
		 show_mouse();
		 get_mouse();
	       if(o.x.bx==1&&o.x.cx<70&&o.x.cx>2&&o.x.dx<25&&o.x.dx>1)
	       {
			//Back
			sound(999);
			setfillstyle(1,14);
			bar(2,1,70,25);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(10,0,"Back");
			delay(200);
			nosound();
			cleardevice();
			admin_main();
		}
		if(o.x.bx==1&&o.x.cx<638&&o.x.cx>570&&o.x.dx<25&&o.x.dx>1)
		{
			//Exit
			sound(999);
			setlinestyle(0,0,2);
			rectangle(569,1,639,25);
			setfillstyle(1,14);
			bar(570,1,638,25);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(585,0,"Exit");
			nosound();
			delay(200);
			cleardevice();
			exit_screen();
		}
		if(o.x.bx==1&&o.x.cx<90&&o.x.cx>10&&o.x.dx<51&&o.x.dx>29)
		{
			//1st Sem Clicking
			sound(999);
			setcolor(9);
			setlinestyle(0,0,2);
			rectangle(9,28,91,52);
			setfillstyle(1,14);
			bar(10,29,90,51);
			setcolor(9);
			settextstyle(1,0,1);
			outtextxy(12,29,"1st.Sem.");
			nosound();
			delay(200);
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(9,53,91,235);
			setfillstyle(1,3);
			bar(10,55,90,234);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(28,56,"101");
			setcolor(15);
			line(27,80,90,80);
			setcolor(14);
			outtextxy(28,82,"102");
			setcolor(15);
			line(27,110,90,110);
			setcolor(14);
			outtextxy(28,112,"103");
			setcolor(15);
			line(27,140,90,140);
			setcolor(14);
			outtextxy(28,142,"104");
			setcolor(15);
			line(27,170,90,170);
			setcolor(14);
			outtextxy(28,173,"105");
			setcolor(15);
			line(27,200,90,200);
			setcolor(14);;
			outtextxy(28,203,"106");
		       delay(250);
		       //	cleardevice();
		      mouse_delete_notes_1st_sem();



		}
		if(o.x.bx==1&&o.x.cx<213&&o.x.cx>120&&o.x.dx<51&&o.x.dx>29)
		{
			//2nd Sem Clicking
			sound(999);
			setcolor(9);
			setlinestyle(0,0,2);
			rectangle(119,28,214,52);
			setfillstyle(1,14);
			bar(120,29,213,51);
			setcolor(9);
			settextstyle(1,0,1);
			outtextxy(127,29,"2nd.Sem.");
			nosound();
			delay(200);
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(119,55,214,235);
			setfillstyle(1,3);
			bar(120,56,213,234);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(150,56,"201");
			setcolor(15);
			line(149,82,213,82);
			setcolor(14);
			outtextxy(150,82,"202");
			setcolor(15);
			line(149,110,213,110);
			setcolor(14);
			outtextxy(150,112,"203");
			setcolor(15);
			line(149,140,213,140);
			setcolor(14);
			outtextxy(150,142,"204");
			setcolor(15);
			line(149,170,213,170);
			setcolor(14);
			outtextxy(150,173,"205");
			setcolor(15);
			line(149,200,213,200);
			setcolor(14);
			outtextxy(150,203,"206");
			delay(1500);
			cleardevice();
			delete_notes_main_screen();


		}
		if(o.x.bx==1&&o.x.cx<320&&o.x.cx>235&&o.x.dx<51&&o.x.dx>29)
		{
			//3rd Sem Clicking
			sound(999);
			setcolor(9);
			setlinestyle(0,0,2);
			rectangle(234,28,321,52);
			setfillstyle(1,14);
			bar(235,29,320,51);
			setcolor(9);
			settextstyle(1,0,1);
			outtextxy(238,29,"3rd.Sem.");
			nosound();
			delay(200);
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(234,55,321,235);
			setfillstyle(1,3);
			bar(235,56,320,234);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(262,56,"301");
			setcolor(15);
			line(261,82,320,82);
			setcolor(14);
			outtextxy(262,82,"302");
			setcolor(15);
			line(261,110,320,110);
			setcolor(14);
			outtextxy(262,112,"303");
			setcolor(15);
			line(261,140,320,140);
			setcolor(14);
			outtextxy(262,142,"304");
			setcolor(15);
			line(261,170,320,170);
			setcolor(14);
			outtextxy(262,173,"305");
			setcolor(15);
			line(261,200,320,200);
			setcolor(14);
			outtextxy(262,203,"306");
			delay(1500);
			cleardevice();
			delete_notes_main_screen();


		}
		if(o.x.bx==1&&o.x.cx<425&&o.x.cx>340&&o.x.dx<51&&o.x.dx>29)
		{
			//4th Sem Clicking
			sound(999);
			setcolor(9);
			setlinestyle(0,0,2);
			rectangle(339,28,426,52);
			setfillstyle(1,14);
			bar(340,29,425,51);
			setcolor(9);
			settextstyle(1,0,1);
			outtextxy(342,29,"4th.Sem.");
			nosound();
			delay(200);
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(339,55,426,235);
			setfillstyle(1,3);
			bar(340,56,425,234);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(363,56,"401");
			setcolor(15);
			line(361,82,425,82);
			setcolor(14);
			outtextxy(363,82,"402");
			setcolor(15);
			line(361,110,425,110);
			setcolor(14);
			outtextxy(363,112,"403");
			setcolor(15);
			line(361,140,425,140);
			setcolor(14);
			outtextxy(363,142,"404");
			setcolor(15);
			line(361,170,425,170);
			setcolor(14);
			outtextxy(363,173,"405");
			setcolor(15);
			line(361,200,425,200);
			setcolor(14);
			outtextxy(363,203,"406");
			delay(1500);
			cleardevice();
			delete_notes_main_screen();


		}
		if(o.x.bx==1&&o.x.cx<525&&o.x.cx>440&&o.x.dx<51&&o.x.dx>29)
		{
			//5th Sem Clicking
			sound(999);
			setcolor(9);
			setlinestyle(0,0,2);
			rectangle(439,28,526,52);
			setfillstyle(1,14);
			bar(440,29,525,51);
			setcolor(9);
			settextstyle(1,0,1);
			outtextxy(443,29,"5th.Sem.");
			nosound();
			delay(200);
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(439,55,526,235);
			setfillstyle(1,3);
			bar(440,56,525,234);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(466,56,"501");
			setcolor(15);
			line(464,82,525,82);
			setcolor(14);
			outtextxy(466,82,"502");
			setcolor(15);
			line(464,110,525,110);
			setcolor(14);
			outtextxy(466,112,"503");
			setcolor(15);
			line(464,140,525,140);
			setcolor(14);
			outtextxy(466,142,"504");
			setcolor(15);
			line(464,170,525,170);
			setcolor(14);
			outtextxy(466,173,"505");
			setcolor(15);
			line(464,200,525,200);
			setcolor(14);
			outtextxy(466,203,"506");
			delay(1500);
			cleardevice();
			delete_notes_main_screen();



		}
		if(o.x.bx==1&&o.x.cx<628&&o.x.cx>542&&o.x.dx<51&&o.x.dx>29)
		{
		       //	cleardevice();
		     //	add_notes_main_screen();
			//6th Sem Clicking
			sound(999);
			setcolor(9);
			setlinestyle(0,0,2);
			rectangle(541,28,629,52);
			setfillstyle(1,14);
			bar(542,29,628,51);
			setcolor(9);
			settextstyle(1,0,1);
			outtextxy(544,29,"6th.Sem.");
			nosound();
			delay(200);
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(541,55,629,235);
			setfillstyle(1,3);
			bar(542,56,628,234);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(569,56,"601");
			setcolor(15);
			line(568,82,628,82);
			setcolor(14);
			outtextxy(569,82,"602");
			setcolor(15);
			line(568,110,628,110);
			setcolor(14);
			outtextxy(569,112,"603");
			setcolor(15);
			line(568,140,628,140);
			setcolor(14);
			outtextxy(569,142,"604");
			setcolor(15);
			line(568,170,628,170);
			setcolor(14);
			outtextxy(569,173,"605");
			setcolor(15);
			line(568,200,628,200);
			setcolor(14);
			outtextxy(569,203,"606");
			delay(1500);
			cleardevice();
			delete_notes_main_screen();
		}
      }


}
//Mouse Detection for Delete Notes For 1st sem
void mouse_delete_notes_1st_sem()
{                   /*
       //initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
   //	while(!kbhit())
   while(1)
      {
		  o.x.bx=0;
		 show_mouse();
		 get_mouse();
		if(o.x.bx==1&&o.x.cx<91&&o.x.cx>9&&o.x.dx<83&&o.x.dx>53)
		{
			//101
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(9,53,91,83);
			setfillstyle(1,14);
			bar(10,54,90,82);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(28,56,"101");
			delay(250);
			nosound();
			delay(100);
		  //	add_notes_main_screen();
	//	  write_notes_1st_sem_101_secrrn();
		}
		if(o.x.bx==1&&o.x.cx<91&&o.x.cx>9&&o.x.dx<110&&o.x.dx>80)
		{
			//102
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(9,80,91,110);
			setfillstyle(1,14);
			bar(10,81,90,109);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(28,82,"102");
			delay(250);
			nosound();
			delay(100);
		     //	add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<91&&o.x.cx>9&&o.x.dx<140&&o.x.dx>110)
		{
			//103
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(9,110,91,140);
			setfillstyle(1,14);
			bar(10,111,90,139);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(28,112,"103");
			delay(250);
			nosound();
			delay(100);
		       //	add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<91&&o.x.cx>9&&o.x.dx<170&&o.x.dx>140)
		{
			//104
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(9,140,91,170);
			setfillstyle(1,14);
			bar(10,141,90,169);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(28,142,"104");
			delay(250);
			nosound();
			delay(100);
			//add_notes_main_screen();
		}
	      if(o.x.bx==1&&o.x.cx<91&&o.x.cx>9&&o.x.dx<200&&o.x.dx>170)
		{
			//105
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(9,170,91,200);
			setfillstyle(1,14);
			bar(10,171,90,199);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(28,173,"105");
			delay(250);
			nosound();
			delay(100);
		//	add_notes_main_screen();
		}
		if(o.x.bx==1&&o.x.cx<91&&o.x.cx>9&&o.x.dx<235&&o.x.dx>200)
		{
			//106
			sound(999);
			setcolor(8);
			setlinestyle(0,0,2);
			rectangle(9,200,91,235);
			setfillstyle(1,14);
			bar(10,201,90,234);
			setcolor(8);
			settextstyle(1,0,1);
			outtextxy(28,203,"106");
			delay(250);
			nosound();
			delay(100);
		  //	add_notes_main_screen();
		}

      }               */
}
//Mouse Detection for Delete Notes For 22n sem
void mouse_delete_notes_2nd_sem()
{

}
//Mouse Detection for Delete Notes For 3rd sem
void mouse_delete_notes_3rd_sem()
{

}
//Mouse Detection for Delete Notes For 4th sem
void mouse_delete_notes_4th_sem()
{

}
//Mouse Detection for Delete Notes For 5th sem
void mouse_delete_notes_5th_sem()
{

}
//Mouse Detection for Delete Notes For 5th sem
void mouse_delete_notes_6th_sem()
{

}


//Make function for delete notes mouse detection menu
//and all crosponding function
















//////////////////////////////////////////////////////
// view notes main screen for viewing notes for each sem one by one
void view_notes_main_screen()
{
	 cleardevice();
	//Center name
	setcolor(15);
	line(2,444,669,444);
	setfillstyle(1,9);
	bar(2,445,669,480);
	settextstyle(1,0,4);
	setcolor(14);
	settextstyle(1,0,4);
	setcolor(14);
	outtextxy(120,441," DEEPAK COMPUTER CENTER ");
	outtextxy(121,441," DEEPAK COMPUTER CENTER ");
	outtextxy(122,441," DEEPAK COMPUTER CENTER ");
	 // Add Notes Messege
	 setfillstyle(1,10);
	 bar(1,1,670,25);
	 setfillstyle(1,7);
	 bar(250,0,420,25);
	 setlinestyle(1,0,5);
	 rectangle(250,0,420,25);
	 setcolor(9);
	settextstyle(1,0,2);
	outtextxy(280,0,"View Note's.");
	//Ribbon
	setcolor(14);
	//Top line
	line(0,0,670,0);
	line(1,0,670,0);
	//Secoand line
	line(0,26,670,26);
	line(0,27,670,27);
	//Third line
	line(0,52,670,52);
	line(0,53,670,53);
	setfillstyle(1,7);
	bar(0,28,670,51);
	//left line
	line(0,0,0,640);
	line(1,0,1,640);
	//Right line
	line(639,0,639,640);
	line(638,0,638,640);
	// Tabs
	//1st Sem.
	setcolor(6);
       //	rectangle(10,29,90,51);
	setcolor(9);
	settextstyle(1,0,1);
	outtextxy(12,29,"1st.Sem.");
	//2nd Sem.
	setcolor(3);
       //	rectangle(120,29,213,51);
	setcolor(9);
	settextstyle(1,0,1);
	outtextxy(127,29,"2nd.Sem.");
	//3rd Sem.
	setcolor(5);
       //	rectangle(235,29,320,51);
	setcolor(9);
	settextstyle(1,0,1);
	outtextxy(238,29,"3rd.Sem.");
	//4th Sem.
	setcolor(4);
       //	rectangle(340,29,425,51);
	setcolor(9);
	settextstyle(1,0,1);
	outtextxy(342,29,"4th.Sem.");
	//5th Sem
	setcolor(15);
       //	rectangle(440,29,525,51);
	setcolor(9);
	settextstyle(1,0,1);
	outtextxy(443,29,"5th.Sem.");
	//6th Sem.
	setcolor(5);
       //	rectangle(542,29,628,51);
	setcolor(9);
	settextstyle(1,0,1);
	outtextxy(544,29,"6th.Sem.");
       //	setcolor(15);
	//Back
       //	rectangle(2,1,70,25);
	setcolor(9);
	settextstyle(1,0,2);
	outtextxy(10,0,"Back");

	//Exit
       //	rectangle(570,1,638,25);
	setcolor(9);
	settextstyle(1,0,2);
	outtextxy(585,0,"Exit");
	mouse_view_notes_main_screen();
}
//Mouse Detrection For View Notes  Main Screen Screen
void mouse_view_notes_main_screen()
{
	//initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
   //	while(!kbhit())
   while(1)
      {
		  o.x.bx=0;
		 show_mouse();
		 get_mouse();
	       if(o.x.bx==1&&o.x.cx<70&&o.x.cx>2&&o.x.dx<25&&o.x.dx>1)
	       {
			//Back
			sound(999);
			setfillstyle(1,14);
			bar(2,1,70,25);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(10,0,"Back");
			delay(200);
			nosound();
			cleardevice();
			admin_main();
		}
		if(o.x.bx==1&&o.x.cx<638&&o.x.cx>570&&o.x.dx<25&&o.x.dx>1)
		{
			//Exit
			sound(999);
			setlinestyle(0,0,2);
			rectangle(569,1,639,25);
			setfillstyle(1,14);
			bar(570,1,638,25);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(585,0,"Exit");
			nosound();
			delay(200);
			cleardevice();
			exit_screen();
		}
		if(o.x.bx==1&&o.x.cx<90&&o.x.cx>10&&o.x.dx<51&&o.x.dx>29)
		{
			//1st Sem Clicking
			sound(999);
			setcolor(9);
			setlinestyle(0,0,2);
			rectangle(9,28,91,52);
			setfillstyle(1,14);
			bar(10,29,90,51);
			setcolor(9);
			settextstyle(1,0,1);
			outtextxy(12,29,"1st.Sem.");
			nosound();
			delay(200);
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(9,53,91,235);
			setfillstyle(1,3);
			bar(10,55,90,234);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(28,56,"101");
			setcolor(15);
			line(27,80,90,80);
			setcolor(14);
			outtextxy(28,82,"102");
			setcolor(15);
			line(27,110,90,110);
			setcolor(14);
			outtextxy(28,112,"103");
			setcolor(15);
			line(27,140,90,140);
			setcolor(14);
			outtextxy(28,142,"104");
			setcolor(15);
			line(27,170,90,170);
			setcolor(14);
			outtextxy(28,173,"105");
			setcolor(15);
			line(27,200,90,200);
			setcolor(14);;
			outtextxy(28,203,"106");
		       delay(250);
		       //	cleardevice();
			view_notes_main_screen();

		}
		if(o.x.bx==1&&o.x.cx<213&&o.x.cx>120&&o.x.dx<51&&o.x.dx>29)
		{
			//2nd Sem Clicking
			sound(999);
			setcolor(9);
			setlinestyle(0,0,2);
			rectangle(119,28,214,52);
			setfillstyle(1,14);
			bar(120,29,213,51);
			setcolor(9);
			settextstyle(1,0,1);
			outtextxy(127,29,"2nd.Sem.");
			nosound();
			delay(200);
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(119,55,214,235);
			setfillstyle(1,3);
			bar(120,56,213,234);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(150,56,"201");
			setcolor(15);
			line(149,82,213,82);
			setcolor(14);
			outtextxy(150,82,"202");
			setcolor(15);
			line(149,110,213,110);
			setcolor(14);
			outtextxy(150,112,"203");
			setcolor(15);
			line(149,140,213,140);
			setcolor(14);
			outtextxy(150,142,"204");
			setcolor(15);
			line(149,170,213,170);
			setcolor(14);
			outtextxy(150,173,"205");
			setcolor(15);
			line(149,200,213,200);
			setcolor(14);
			outtextxy(150,203,"206");
			delay(1500);
			cleardevice();
			view_notes_main_screen();

		}
		if(o.x.bx==1&&o.x.cx<320&&o.x.cx>235&&o.x.dx<51&&o.x.dx>29)
		{
			//3rd Sem Clicking
			sound(999);
			setcolor(9);
			setlinestyle(0,0,2);
			rectangle(234,28,321,52);
			setfillstyle(1,14);
			bar(235,29,320,51);
			setcolor(9);
			settextstyle(1,0,1);
			outtextxy(238,29,"3rd.Sem.");
			nosound();
			delay(200);
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(234,55,321,235);
			setfillstyle(1,3);
			bar(235,56,320,234);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(262,56,"301");
			setcolor(15);
			line(261,82,320,82);
			setcolor(14);
			outtextxy(262,82,"302");
			setcolor(15);
			line(261,110,320,110);
			setcolor(14);
			outtextxy(262,112,"303");
			setcolor(15);
			line(261,140,320,140);
			setcolor(14);
			outtextxy(262,142,"304");
			setcolor(15);
			line(261,170,320,170);
			setcolor(14);
			outtextxy(262,173,"305");
			setcolor(15);
			line(261,200,320,200);
			setcolor(14);
			outtextxy(262,203,"306");
			delay(1500);
			cleardevice();
			view_notes_main_screen();

		}
		if(o.x.bx==1&&o.x.cx<425&&o.x.cx>340&&o.x.dx<51&&o.x.dx>29)
		{
			//4th Sem Clicking
			sound(999);
			setcolor(9);
			setlinestyle(0,0,2);
			rectangle(339,28,426,52);
			setfillstyle(1,14);
			bar(340,29,425,51);
			setcolor(9);
			settextstyle(1,0,1);
			outtextxy(342,29,"4th.Sem.");
			nosound();
			delay(200);
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(339,55,426,235);
			setfillstyle(1,3);
			bar(340,56,425,234);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(363,56,"401");
			setcolor(15);
			line(361,82,425,82);
			setcolor(14);
			outtextxy(363,82,"402");
			setcolor(15);
			line(361,110,425,110);
			setcolor(14);
			outtextxy(363,112,"403");
			setcolor(15);
			line(361,140,425,140);
			setcolor(14);
			outtextxy(363,142,"404");
			setcolor(15);
			line(361,170,425,170);
			setcolor(14);
			outtextxy(363,173,"405");
			setcolor(15);
			line(361,200,425,200);
			setcolor(14);
			outtextxy(363,203,"406");
			delay(1500);
			cleardevice();
			view_notes_main_screen();

		}
		if(o.x.bx==1&&o.x.cx<525&&o.x.cx>440&&o.x.dx<51&&o.x.dx>29)
		{
			//5th Sem Clicking
			sound(999);
			setcolor(9);
			setlinestyle(0,0,2);
			rectangle(439,28,526,52);
			setfillstyle(1,14);
			bar(440,29,525,51);
			setcolor(9);
			settextstyle(1,0,1);
			outtextxy(443,29,"5th.Sem.");
			nosound();
			delay(200);
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(439,55,526,235);
			setfillstyle(1,3);
			bar(440,56,525,234);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(466,56,"501");
			setcolor(15);
			line(464,82,525,82);
			setcolor(14);
			outtextxy(466,82,"502");
			setcolor(15);
			line(464,110,525,110);
			setcolor(14);
			outtextxy(466,112,"503");
			setcolor(15);
			line(464,140,525,140);
			setcolor(14);
			outtextxy(466,142,"504");
			setcolor(15);
			line(464,170,525,170);
			setcolor(14);
			outtextxy(466,173,"505");
			setcolor(15);
			line(464,200,525,200);
			setcolor(14);
			outtextxy(466,203,"506");
			delay(1500);
			cleardevice();
			view_notes_main_screen();


		}
		if(o.x.bx==1&&o.x.cx<628&&o.x.cx>542&&o.x.dx<51&&o.x.dx>29)
		{
		       //	cleardevice();
		     //	add_notes_main_screen();
			//6th Sem Clicking
			sound(999);
			setcolor(9);
			setlinestyle(0,0,2);
			rectangle(541,28,629,52);
			setfillstyle(1,14);
			bar(542,29,628,51);
			setcolor(9);
			settextstyle(1,0,1);
			outtextxy(544,29,"6th.Sem.");
			nosound();
			delay(200);
		     //	cleardevice();
		      // add_notes_main_screen();
			//Showing Menu
			setlinestyle(0,0,2);
			rectangle(541,55,629,235);
			setfillstyle(1,3);
			bar(542,56,628,234);
			setcolor(14);
			settextstyle(1,0,2);
			outtextxy(569,56,"601");
			setcolor(15);
			line(568,82,628,82);
			setcolor(14);
			outtextxy(569,82,"602");
			setcolor(15);
			line(568,110,628,110);
			setcolor(14);
			outtextxy(569,112,"603");
			setcolor(15);
			line(568,140,628,140);
			setcolor(14);
			outtextxy(569,142,"604");
			setcolor(15);
			line(568,170,628,170);
			setcolor(14);
			outtextxy(569,173,"605");
			setcolor(15);
			line(568,200,628,200);
			setcolor(14);
			outtextxy(569,203,"606");
			delay(1500);
			cleardevice();
			view_notes_main_screen();
	     }
      }

}











/*

//*************************************************************
//*************Teacher Login Functions*************************
//Semester Selection window for login as teacher
void teacher_log_sem_selection_window()
{
	cleardevice();
	outline();
	cn();
	// outline
	setcolor(15);
	rectangle(120,110,520,400);
	rectangle(121,111,520,400);
	rectangle(119,109,521,401);
	rectangle(121,111,521,152);
	setfillstyle(1,3);
	bar(122,112,519,151);
	setfillstyle(1,7);
	bar(122,153,519,399);
	setcolor(14);
	settextstyle(1,0,3);
	outtextxy(123,111,"Select Semester For Login As Teacher");
	outtextxy(123,111,"Select Semester For Login As Teacher");
	//Back Button
	setcolor(15);
	rectangle(121,230,150,310);
	setfillstyle(1,8);
	bar(122,231,149,309);
	settextstyle(1,0,3);
	outtextxy(125,232,"B");
	outtextxy(125,246,"a");
	outtextxy(125,260,"c");
	outtextxy(125,277,"k");
	//Exit Button
	setcolor(15);
	rectangle(490,231,519,309);
	setfillstyle(1,8);
	bar(491,232,518,308);
	setcolor(15);
	outtextxy(495,232,"E");
	outtextxy(495,246,"x");
	outtextxy(495,265,"i");
	outtextxy(495,281,"t");
	//1st sem. Button
	setcolor(15);
	rectangle(230,160,400,190);
	setfillstyle(1,5);
	bar(231,161,399,189);
	settextstyle(1,0,2);
	outtextxy(270,161,"1st Sem.");
	outtextxy(270,161,"1st Sem.");
	//2nd Sem. Button
	setcolor(15);
	rectangle(231,200,400,230);
	setfillstyle(1,5);
	bar(232,201,399,229);
	outtextxy(270,202,"2nd Sem.");
	outtextxy(270,202,"2nd Sem.");
	//3rd Sem. Button
	setcolor(15);
	rectangle(231,240,400,270);
	setfillstyle(1,5);
	bar(232,241,399,269);
	outtextxy(270,243,"3rd Sem.");
	outtextxy(270,243,"3rd Sem.");
	//4th Sem. Button
	setcolor(15);
	rectangle(231,280,400,310);
	setfillstyle(1,5);
	bar(232,281,399,309);
	outtextxy(270,283,"4th Sem.");
	outtextxy(270,283,"4th Sem.");
	//5th Sem. Button
	setcolor(15);
	rectangle(231,320,400,350);
	setfillstyle(1,5);
	bar(232,321,399,349);
	outtextxy(270,320,"5th Sem.");
	outtextxy(270,320,"5th Sem.");
	//6th Sem Button
	setcolor(15);
	rectangle(231,360,400,390);
	setfillstyle(1,5);
	bar(232,361,399,389);
	outtextxy(270,360,"6th Sem.");
	outtextxy(270,360,"6th Sem.");
//	cleardevice();
	delay(250);
	mouse_teacher_log_sem_selection_window();


}
//mouse Detection for Login as  teacher for each semester
void mouse_teacher_log_sem_selection_window()
{
   //initilizing mouse for this block
	initialize_mouse();
	show_mouse();
	//check_button_status();
	while(1)//!kbhit())
      // while(!kbhit())
       {
		 o.x.bx=0;
		 show_mouse();
		 get_mouse();
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<200&&o.x.dx>160)
		 {
			//1st Sem. clicking
			sound(999);
			setcolor(15);
			rectangle(230,160,400,190);
			setfillstyle(1,14);
			bar(231,161,399,189);
			setcolor(8);
			settextstyle(1,0,2);
			outtextxy(270,161,"1st Sem.");
			outtextxy(270,161,"1st Sem.");
			delay(250);
			nosound();
			//delay(1000);
		       //	cleardevice();
			teacher_log_sem_selection_window();
		 }
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<230&&o.x.dx>200)
		{
			//2nd Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,200,400,230);
			setfillstyle(1,14);
			bar(232,201,399,229);
			setcolor(8);
			outtextxy(270,202,"2nd Sem.");
			outtextxy(270,202,"2nd Sem.");
			delay(100);
			nosound();

		       //	delay(1000);
			//cleardevice();
			teacher_log_sem_selection_window();
		}
		 if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<270&&o.x.dx>240)
		{
			//3rd Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,240,400,270);
			setfillstyle(1,14);
			bar(232,241,399,269);
			setcolor(8);
			outtextxy(270,243,"3rd Sem.");
			outtextxy(270,243,"3rd Sem.");
			delay(100);
			nosound();

		      //	delay(1000);
		    //	cleardevice();
			teacher_log_sem_selection_window();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<310&&o.x.dx>280)
		{
			//4th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,280,400,310);
			setfillstyle(1,14);
			bar(232,281,399,309);
			setcolor(8);
			outtextxy(270,283,"4th Sem.");
			outtextxy(270,283,"4th Sem.");
			delay(100);
			nosound();

			//delay(1000);
			//cleardevice();
			teacher_log_sem_selection_window();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<350&&o.x.dx>320)
		{
			//5th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,320,400,350);
			setfillstyle(1,14);
			bar(232,321,399,349);
			setcolor(8);
			outtextxy(270,320,"5th Sem.");
			outtextxy(270,320,"5th Sem.");
			delay(100);
			nosound();


		      ///	delay(1000);
		    //	cleardevice();
			teacher_log_sem_selection_window();
		}
		if(o.x.bx==1&&o.x.cx<400&&o.x.cx>230&&o.x.dx<390&&o.x.dx>360)
		{
			//6th Sem. Clicking
			sound(999);
			setcolor(15);
			rectangle(231,360,400,390);
			setfillstyle(1,14);
			bar(232,361,399,389);
			setcolor(8);
			outtextxy(270,360,"6th Sem.");
			outtextxy(270,360,"6th Sem.");
			delay(100);
			nosound();
		      //	delay(1000);
		    //	cleardevice();
			teacher_log_sem_selection_window();
		}
		if(o.x.bx==1&&o.x.cx<150&&o.x.cx>127&&o.x.dx<310&&o.x.dx>230)
		{
			//Back Button  Clicking
			sound(999);
			setcolor(15);
			rectangle(121,230,150,310);
			setfillstyle(1,14);
			bar(122,231,149,309);
			setcolor(8);
			settextstyle(1,0,3);
			outtextxy(125,232,"B");
			outtextxy(125,246,"a");
			outtextxy(125,260,"c");
			outtextxy(125,277,"k");
			delay(100);
			nosound();
			cleardevice();
			login_menu();
		}
		if(o.x.bx==1&&o.x.cx<519&&o.x.cx>490&&o.x.dx<310&&o.x.dx>230)
		{
			//Exit Button  Clicking
			sound(999);
			setcolor(15);
			rectangle(490,231,519,309);
			setfillstyle(1,14);
			bar(491,232,518,308);
			setcolor(8);
			outtextxy(495,232,"E");
			outtextxy(495,246,"x");
			outtextxy(495,265,"i");
			outtextxy(495,281,"t");
			delay(250);
			nosound();
			cleardevice();
			exit_screen();
		}

	  }

}

  */
void main()
{

	int gd = DETECT, gm;
	void exit_screen();
	/*
	registerfarbgidriver(EGAVGA_driver_far);
	registerfarbgifont(sansserif_font_far);
	registerfarbgifont(gothic_font_far);
	registerfarbgifont(triplex_font_far);
				     */
	initgraph(&gd, &gm,"C:\\turboc3\\bgi");
	window(1,1,40,25);
	setbkcolor(12);
	// Start Function Calling
     welcome_screen();
// add_notes_main_screen();
 //	admin_main();
clrscr();
getch();
closegraph();
}
/* Exit screen	*/
void exit_screen()
{     	cleardevice();
	outline();
	setlinestyle(0,0,2);
	rectangle(109,94,531,306);
	setfillstyle(1,5);
	bar(110,95,530,305);
	rectangle(115,100,525,299);

	setfillstyle(1,4);
	bar(116,102,524,298);
	settextstyle(1,0,3);
	setcolor(14);
	outtextxy(224,100,"Thanks For Using...");
	outtextxy(225,100,"Thanks For Using...");
	setcolor(15);
	line(115,137,525,137);
	setcolor(2);
	setlinestyle(0,1,2);
	setcolor(15);
	settextstyle(1,0,1);
	outtextxy(120,142,"Design & Developed By :-");
	setfillstyle(1,10);
	bar(116,170,524,203);
	settextstyle(1,0,4);
	setcolor(1);
	outtextxy(185,165," DEEPAK SINGH ");
	setcolor(1);
	outtextxy(185,166," DEEPAK SINGH ");
	outtextxy(185,167," DEEPAK SINGH ");
	setcolor(1);
	outtextxy(185,168," DEEPAK SINGH ");

	setcolor(15);
	settextstyle(7,0,3);
	outtextxy(120,202,"Contact for more...");
	line(117,230,335,230);

	setcolor(10);
	settextstyle(1,0,2);
	outtextxy(118,237,"Phone :- 9525357044");
	settextstyle(1,0,2);
	outtextxy(118,260,"Email :- deepsinghkumar01@gmail.com");
	setcolor(8);
	line(170,330,460,330);
	setcolor(15);
	settextstyle(1,0,2);
	outtextxy(210,330,"Exiting please wait !...");
	setcolor(8);
	line(170,360,460,360);
	setcolor(15);
	settextstyle(1,0,2);
	outtextxy(265,370,"-d..$!ng#");
	delay(5000);
	sound(9999);
	cleardevice();
	delay(30);
	nosound();
	cleardevice();
	exit(0);
}
