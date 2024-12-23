//dukou.h

//Sample for room: 龙门渡口
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_dukou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "龙门渡口");

   	add_door("黄河2", "黄河2", "黑木崖龙门渡口");
	add_door("黄河黄土高原", "黄河黄土高原", "黑木崖龙门渡口");		
	add_door("黑木崖黄土路4", "黑木崖黄土路4", "黑木崖龙门渡口");
	add_door("华山村青石大道", "华山村青石大道", "黑木崖龙门渡口");

	
				
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
	add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}

	set("long", "渡口前就是汹涌澎湃的黄河(he)了。浊流滚滚，泥沙俱下，声震数里。两岸渡船来来往往，在波谷中穿行，甚为凶险。过了黄河，就是陕西了。");
    

/*****************************************************
    set("exits", ([
        "northeast" : __DIR__"road4",
    ]));
    set("item_desc", ([
        "he" : "一叶小舟摇摆不定地顶风前行，喊(yell)一声试看。\n",
    ]));
********************************************/
};


ROOM_END;
