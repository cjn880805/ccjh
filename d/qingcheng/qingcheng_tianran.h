//tianran.h

//Sample for room: �����Ȼͼ��
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_tianran);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����Ȼͼ��");
	
	add_npc("qingcheng_hai");    //add by zdn 2001-07-20


	add_door("���ɽ·2", "���ɽ·2", "�����Ȼͼ��");
	add_door("���פ��ׯ", "���פ��ׯ", "�����Ȼͼ��");
	add_door("�����ɽ���", "�����ɽ���", "�����Ȼͼ��");


    

/*****************************************************
	set("exits", ([
		"eastdown" : __DIR__"path1",
		"westup"   : __DIR__"path2",
		"north"    : __DIR__"zhuhezhuang",
	]));
*****************************************************/
};


ROOM_END;
