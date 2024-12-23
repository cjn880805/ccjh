//jiudain.h

//Sample for room: ����¥
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_jiudain);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����¥");

	//add npcs into the room
	add_npc("pub_xiaoer2");/////////////////////////

	add_door("���ݱ�", "���ݱ�", "���ݴ���¥");

	set("long", "����һ�����ݳ��������ľ�¥������¥���Ե��Ϊ��ɫ��ש��ľ��ʯ���߽�¥�ڣ�һ�۱㿴��һ����������ͼ�������˱��軭��Ω��ΩФ��¥������ϱ��������ſ���������Ʒ�裬ֻ����С��æ�Ĳ����ֺ���" );
 	set("outdoors", "suzhou");
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
