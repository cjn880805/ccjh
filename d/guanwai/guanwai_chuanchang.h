//chuanchang.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuanWai_chuanchang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	set("monster_chance", 50);

	add_npc("lj_yudafu"); 

	add_door("����ѩ��3", "����ѩ��3", "���⴬��");
	add_door("�������", "�������", "���⴬��");

    set("long","�����ǹ��򴬳���������λ�ڹ����ƽԭ�в���һ�����ϵ�С�򣬴��������ϡ������������Ը�ǽ���������ڼ��ء��������ɻ���������գ��˱��ұ�����Ҫ�ء��ɻ����ڶ���ʱ�����ͨ�У����ﻯ����ֻ���Ҵ��Ұ�æ�ˡ�" );
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
