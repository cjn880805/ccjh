//gytoad2.h

//Sample for room: �䵱��԰С·2
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_gytoad2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱��԰С·2");


	add_door("�䵱��԰С·1", "�䵱��԰С·1", "�䵱��԰С·2");
	add_door("�䵱��԰", "�䵱��԰", "�䵱��԰С·2");

    	
	set("guocount",1);

/*****************************************************
	set("outdoors", "wudang");
	set("item_desc", ([
		"tree" : 
"����һ���˲ι�������������˲ι�����˵ժ�³��˶��书������кô���\n"
	]));
	set("exits", ([
		"west" : __DIR__"gyroad1",
	]));
*****************************************************/
};


ROOM_END;
