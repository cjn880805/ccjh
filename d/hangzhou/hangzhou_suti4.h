//suti4.h

//Sample for room: �����յ�4
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_suti4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����յ�4");

	//add npcs into the room
	add_npc("wudang_liyuanzhi");

	add_door("�����յ�3", "�����յ�3", "�����յ�4");
	add_door("�����յ�5", "�����յ�5", "�����յ�4");

	set("long"," ����������������ϣ�������ɴ��ȸ������һƬ�������յ̴�������Ϊ����ʮ��֮�ף���Ȼ�����鴫��������ѹ���ţ���������ɽ�š�����һƬ÷�֣��ֺ��ƺ�����Ժ�䣬���������С�");

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
