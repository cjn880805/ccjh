//fangjian1.h

//Sample for room: ����1
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRSheShenYa_fangjian1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����·���1");


	add_door("������ʯ��", "������ʯ��", "�����·���1");

	set("long","���Կ���������ǰ������һ������ĵط����������һ��ʯ������ֻ����֮�⣬�յ�����һ�����У�ʯ���Ͽ����ݺ�ʮ�ŵ���·������ϲ��Ŷ��ٶ�����ӣ�ȴ�Ǻڰ׶��ţ���Ȼ��һ��û��������塣");
	

/*****************************************************
	set("exits", ([
		"south" : __DIR__"shiji1",
	]));
*****************************************************/
};


ROOM_END;
