//hcaguangchang.h

//Sample for room:  ���һ����ֹ㳡
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcaguangchang);

virtual void create()			//Call it when Room Create
{
	set_name( "���һ����ֹ㳡");

	add_npc("emei_xu");

	add_door("���һ���������", "���һ���������", "���һ����ֹ㳡");
	add_door("���һ����ֶ���1", "���һ����ֶ���1", "���һ����ֹ㳡");
	add_door("���һ���������1", "���һ���������1", "���һ����ֹ㳡");
	add_door("���һ����ִ��۱���", "���һ����ִ��۱���", "���һ����ֹ㳡");

	set("long","�����Ƕ��һ����ֵĹ㳡������������ש����ǰ����һ��̨�ף�ͨ�����۱����ǰ�и�����ߵĴ���¯����¯ǰ����̨�ϣ�������գ�����Ʈ�ơ��㳡���м���Сʦ̫�����������Դ����Ҹ���һ������ͨ���");
    set("valid_startroom","1");

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
