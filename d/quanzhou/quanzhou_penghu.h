//penghu.h

//Sample for room: �����
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_penghu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����");

	set("resident", "���");

	//add npcs into the room
	add_npc("pub_qinbing");/////////////////////////
	add_npc("lj_hajuba");

	add_door("Ȫ�ݺ���", "Ȫ�ݺ���", "Ȫ�������");
	add_door("̨�弦����", "̨�弦����", "Ȫ�������");
	add_door("̨��򹷸�", "̨��򹷸�", "Ȫ�������");

	
/*****************************************************
	set("item_desc", ([
                "chuan" : "һ���󺣴�����Զ��û�����Ĵ��ɲ��С�\n",
                "zhou"  : "һ��ˮ��ս�ۣ�ǰ��̨�壬���ÿ�����\n",
	]));
	set("objects", ([
		__DIR__"npc/liu": 1,
		"/d/city/npc/bing" : 4,
	]));
********************************************/
};


RESIDENT_END;
