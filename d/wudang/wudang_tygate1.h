//tygate1.h

//Sample for room: 冷輝孟坩千以1
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_tygate1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "冷輝孟坩千以1");


	add_door("冷輝孟坩弌揃8", "冷輝孟坩弌揃8", "冷輝孟坩千以1");

    

/*****************************************************
	set("outdoors", "wudang");
	set("item_desc",([
		"fence"	:	"\n\t\t\t千以壇貧嗤遍鮒��\n\n\n" 
					"\t\t）））））））））））））））））））））\n"
					"\t\t）））　　　　　　　　　　　　　　　）））\n"
					"\t\t）））　哘　鮮　繻　掛　咫　稼　巳　）））\n"
					"\t\t）））　　　　　　　　　　　　　　　）））\n"
					"\t\t）））　弌　諏　会　跚　消　音　蝕　）））\n"
					"\t\t）））　　　　　　　　　　　　　　　）））\n"
					"\t\t）））　敢　弼　諾　坩　購　音　廖　）））\n"
					"\t\t）））　　　　　　　　　　　　　　　）））\n"
					"\t\t）））　匯　乢　碕　佯　竃　能　栖　）））\n"
					"\t\t）））　　　　　　　　　　　　　　　）））\n"
					"\t\t）））））））））））））））））））））\n\n\n",
							
	]));
	set("exits", ([
		"south" : __DIR__"tyroad10",
	]));
*****************************************************/
};


ROOM_END;
