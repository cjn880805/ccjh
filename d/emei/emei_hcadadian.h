//hcadadian.h

//Sample for room:  ���һ����ִ��۱���
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcadadian);

virtual void create()			//Call it when Room Create
{
	set_name( "���һ����ִ��۱���");

	add_npc("emei_dao");
	add_npc("pub_ningfeng");
			

	add_door("���һ����ֹ㳡", "���һ����ֹ㳡", "���һ����ִ��۱���");
	add_door("���һ�����ի��", "���һ�����ի��", "���һ����ִ��۱���");
	add_door("���һ���������", "���һ���������", "���һ����ִ��۱���");
	add_door("���һ����ֺ��", "���һ����ֺ��", "���һ����ִ��۱���");

	set("long","���Ƕ���ɽ�����ֵĴ��۱�����й���������������һȺ����Сʦ̫���ڵ����о��������е�С��ͨ����");
    
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




