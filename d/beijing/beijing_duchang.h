//duchang.h

//Sample for room: �ĳ�
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_duchang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ĳ�");


	add_door("��������", "��������", "�����ĳ�");

	set("long", " �����Ƕĳ��Ĵ��ã����ܵķ����ﴫ����ߺ������ĶĲ����������Ƕġ���С���ķ��䣬ǽ�Ϲ���һ������(paizi)��¥�Ͽ��Թ���. һ���ţ�ֻ�������������ӣ�ʮ�ֻ��ҡ���һ��Χ��һȺ�ˣ�����һ��һ������ͷ��ʮ�����ۡ�һ���Ͻл��������Ƕĵ��𾢡�" );
	

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
