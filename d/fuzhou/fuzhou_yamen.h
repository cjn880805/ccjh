//yamen.h

//Sample for room: �ᶽ����
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_yamen);

virtual void create()			//Call it when Room Create
{
	set_name( "�ᶽ����");

	add_npc("pub_geshiha");
	add_npc("pub_dinli");
	
	add_door("������", "������", "�����ᶽ����");

    set("long", "���������Ŵ��ţ�������ľ���Ž����ر��š����ྲ�����رܡ������ӷַ���ͷʯʨ�ӵ��Աߡ�ǰ����һ����ģ�������ʲ��վ����ǰ��" );
	set("no_beg", 1);

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
