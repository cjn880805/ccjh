//fangjian3.h

//Sample for room: ����3
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRSheShenYa_fangjian3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����·���3");


	add_door("������ʯ��", "������ʯ��", "�����·���3");

	set("long","��ֻ������ǰ��Ȼһ����һ����װ����Ů��������һ�ѳ�������׼��������ţ���������һ���龪֮����ŷ���ԭ��ֻ�Ǹ������ɵ����񣬵��ǿ���ȥȴ������һ�����졣�����һ˫����ӨȻ�й⣬��ɷ�����ʱֻ�������Ŀѣ��������ħ��а���۹���Ҳ�벻�����񡣡�����");
	set("book_count",1);

/*****************************************************
	set("exits", ([
		"east" : __DIR__"tongmen",
	]));
	set("objects",([
		__DIR__"obj/putuan" : 1,
	]));
//	
*****************************************************/
};


ROOM_END;
