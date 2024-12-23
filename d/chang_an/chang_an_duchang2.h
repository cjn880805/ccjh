//duchang2.h

//Sample for room: ����������
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_duchang2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");

	add_npc("pub_shinu1");  //2001-07-12 zdn add
	add_npc("pub_xuanyuanguang");  //21����Ϸ 2002��3��22

	add_door("�����ַ���¥����", "�����ַ���¥����", "����������");

	set("long", " �������һ�����������м����һ�����̡��Ŀ������۾�������¶ġ���ϯ��һλ���ӣ����ﲻ����Ū��һ�������������������ׯ����ǽ�Ϲ���һ���ң�����д�ţ�        ͷ�ʣ�������ÿ�ο���ǰȷ����            ��һӮ��ʮ��        ˫�ԣ���������ͬ����Ϊż����            ��һӮʮ��        ���ǣ�����֮��Ϊ�ߣ�                    ��һӮ��        ɢ�ǣ�����֮��Ϊ�����壬�ţ�ʮһ��      ��һӮ���ҽ���һ������(paizi)�� " );
	set("light_up",  1);
	set("no_fight",  1);
	set("no_magic",  1);

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




