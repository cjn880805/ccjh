//qinglindong.h

//Sample for room: �������ֶ�
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_qinglindong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������ֶ�");


	add_door("���ݷ�����", "���ݷ�����", "�������ֶ�");
	add_door("���ݴ�΢ͤ", "���ݴ�΢ͤ", "�������ֶ�");

	set("long","�ֽ��ϻ�����ֻ�����ҵ������ӣ�����������������С�𡣶��ڶ�����ϻ�����һ�顰®���Ƿ�ᡱ�������Ͽ̻�ͷ�裬�м���������Ĳ�ᣬ���ҷ������⣬���ͣ���������������������ɽ��·��С·���������򶫡�" );

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
