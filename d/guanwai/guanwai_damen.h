//damen.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_damen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	set("resident", "�������");

	//add npcs into the room
	add_npc("guanwai_hufei");     // add by zdn 2001-07-13

	add_door("���ⳤ���ٲ�", "���ⳤ���ٲ�", "�������");
	add_door("�������ŷ�", "�������ŷ�", "�������");

    set("long","���������ע������Ω������ƫ��һ��б�����������裬����Ǵ��š���ˮ������������ˮ�����䣬��ʯ�ڼ��ײ������" );
    

/*****************************************************
	set("exits", ([
		"southwest"  : __DIR__"longmen",
		"northwest"  : __DIR__"pubu",
	]));
********************************************/
};


RESIDENT_END;
