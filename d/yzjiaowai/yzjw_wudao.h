//wudao.h

//Sample for room:  ���������
//coded by zwb
//data: 2000-11-22


ROOM_BEGIN(CRYZJW_wudao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���������");

	add_npc("pub3_gongpingzi");

	add_door("�������Ŵ��","�������Ŵ��","���������");

    set("long","�����Ǳ�������ʦϯ���߾���̨֮�ϣ��������ߣ���ľ������������ɽӭˬ�����¿���̨��Χ��ͷ�ܶ������Ϸ���һ��Сľ�� (pai)�����������һ�ź�ֽ��ʾ(gaoshi)��");


/********************************************************
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
		"pai"    : (: look_pai :),
	]));
	set("exits", ([
		"down"      : __DIR__"leitai",
	]));

  for more information look ../yangzhou/wudao.h
********************************************************/
 
};


ROOM_END;
