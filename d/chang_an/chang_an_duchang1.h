//duchang1.h

//Sample for room: ����Ѻǩ��
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_duchang1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ѻǩ��");

	add_npc("pub_punk");  //2001-07-2-12  zdn add
	add_npc("pub_punk"); 
	add_npc("pub_punk"); 
	add_npc("wei_zengrou");

	add_door("�����ַ���¥����", "�����ַ���¥����", "����Ѻǩ��");

	set("long", " һȺ��Χ����̴ľ������������ϯ����һλ���ݵ�ǩ�ͣ�����һ�������ش����ں���������һ��һ��������Ǭ��ǩ�����������ϡ�ǽ����һ��д�ţ�        ��Ǭǩ��ȫ�������ΪǬǩ����һӮ��ʮ��        ����ǩ��ȫ�������Ϊ��ǩ����һӮ��ʮ��        СǬǩ�������ĸ���ΪǬǩ����һӮʮ��        С��ǩ�������ĸ���Ϊ��ǩ����һӮʮ��          Ǭǩ������������ΪǬǩ����һӮ��          ��ǩ������������Ϊ��ǩ����һӮ��       �ҽ���һ������(paizi)�� " );
	set("light_up",  1);
	set("no_fight",  1);
	set("no_beg",  1);

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
