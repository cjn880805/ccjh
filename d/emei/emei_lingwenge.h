//lingwenge.h

//Sample for room:  �������ĸ�
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_lingwenge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������ĸ�");

	add_npc("emei_zhao");
				
	add_door("���Ҹ�����", "���Ҹ�����", "�������ĸ�");

	set("long","�����Ǹ����ֵ����ĸ������־���ʦ̫���ڷ𷨵ĵط�����������С���������ԣ��ƺ�������ʦ̫�Ľ̻ޡ����ڲ��ü�ª����ǽ���ż������Σ����Ϸ��ż������š�������һ������������һ��ի����");

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
