//fengqiao.h

//Sample for room: ∑„«≈
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_fengqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "∑„«≈");
	
	add_npc("pub_playboy");     //add by zdn 2001-07-16


	add_door("À’÷›∫Æ…ΩÀ¬", "À’÷›∫Æ…ΩÀ¬", "À’÷›∑„«≈");
	add_door("À’÷›Ã˙¡Îπÿ", "À’÷›Ã˙¡Îπÿ", "À’÷›∑„«≈");

	

/*****************************************************
	set("exits", ([
		"enter" : __DIR__"hanshidian",
		"north" : __DIR__"tielingguan",
	]));
****************************************************/
};


ROOM_END;
