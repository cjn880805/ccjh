//huanghe_2.h

//Sample for room: �ƺ�2
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe_2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�2");
	
	add_npc("monster_20k");        //add by zdn 2001-07-14
	add_npc("pub_hahazi");

	add_door("�ƺ�3", "�ƺ�3", "�ƺ�2");
	add_door("��ľ�����Ŷɿ�", "��ľ�����Ŷɿ�", "�ƺ�2");

	set("long","�ƺӳ����ຣ��������֮�����ܵ�������ԭ���赲��ת���򶫱���ȥ��������������ԭ�Ĺ�������ɳ����������ˮɫ�λƣ��ͱ���Ϊ�ƺӡ�");
    

/*****************************************************
	set("exits", ([
		"west"      : __DIR__"huanghe_3",
		"northeast" : __DIR__"huangtu",
	]));
********************************************/
};


CHANGAN_END;
