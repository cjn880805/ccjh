//pukeroom.h

//Sample for room: ��������
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_pukeroom);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	add_npc("pub_lady3");

	add_door("�����ָ�ʫ��", "�����ָ�ʫ��", "��������");

	set("long", "���м����һ�ſ������൱��ʵ�Ĵ���(table)������Χ���İѿ���ľ�Ρ�����ǽ����һ�������(paizi)������ǽ����һ��С����(score)��  " );
	set("no_fight",  1);
	set("no_magic",  1);

/*****************************************************
	set("item_desc",  (["paizi"  :  "

�������

��Ҫָ���У�
һ������(sit  <n,  s,  e,  w>)��
��������(start)��
��������(play  <��ɫ>  <��С>)��
������ɫ��(hei,  hong,  cao,  fang)����(S/s,  H/h,  C/c,  D/d)������
������С��(1,  ...,  13)����(A/a,  J/j,  Q/q,  K/k)������(1,  11,  12,  13)��
�ģ���������(double  <zhu/z,  yang/y,  hong/h,  bian/b>)��
�壬���Լ�����(my)��
�������������(look  table)��
�ߣ�������(look  score)��
�ˣ��˳�����(leave)��

ע�����
һ��Ҫ�����Ʒ磬ϵͳ���ҷ���ס�
����ÿһ�̱����ڰ�Сʱ����ɣ�����ȡ��������
�������κ�bug�뱨����ʦ��Ŀǰ�ǲ��Խ׶Σ����ܻ��в��ٴ�

		\n"  ]));
	//for  look  something.

	set("exits",  
	([  //sizeof()  ==  4
		//"south"  :  __DIR__"xiaomuwu",
		//"north"  :  __DIR__"chufang",
		//"west"  :  __DIR__"duchang2",
		"west"  :  __DIR__"clubpoem",
		//"up"  :  __DIR__"***",
		//"down"  :  __DIR__"***",
	]));
	
	set("objects",  
	([  //sizeof()  ==  1
		//__DIR__"npc/gongsun"  :  1,
	]));
	//set("outdoors",  "city");
********************************************/

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

CHANGAN_END;
