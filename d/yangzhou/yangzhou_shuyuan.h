//shuyuan.h

//Sample for room: 书院
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_shuyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "书院");

	//add npcs into the room
	add_npc("pub_zhu");/////////////////////////

	add_door("扬州东北", "扬州东北", "扬州书院");

	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
/*****************************************************
	set("item_desc", ([ 
		"xuegui": "
		日讲经书三起，日看纲目数页。
		通晓时务物理，参读古文诗赋。
		读书必须过笔，会课按时蚤完。
		夜读仍戒晏起，疑误定要力争。

	求学需缴学费五十两。\n",
		"board": "
       本书院奉圣上恩旨自即日起封授学位：
  0       文盲
 10       童生
 20       秀才
 30       举人
 40       解元
 50       贡士
 60       会元
 70       进士
 80       探花
 90       榜眼
100       状元
110       翰林院士
120       翰林硕士
130       翰林博士
140       翰林院编修
150       庶吉士
160       学士
170       内阁大学士
180       内阁首辅
190       文学大宗师
200       圣人\n" 
	]));
	set("exits", ([ 
		"up"    : __DIR__"shuyuan2",
		"south" : __DIR__"dongdajie1",
	]));
	set("objects", ([ 
		__DIR__"npc/zhu" : 1,
	]));
********************************************/
};


ROOM_END;
