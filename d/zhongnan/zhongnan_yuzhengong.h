//yuzhengong.h

//Sample for room: ����ɽ���湬
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_yuzhengong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ���湬");


	add_door("����ɽ������", "����ɽ������", "����ɽ���湬");

    set("long","��������������ǰ�ľ�ַ���������������˲�����֮ǰ���޵ĵط��������ִ�ȫ��̺󣬴˵صĲ���ʵ��̫С���ͽ�������Ǩ������ɽ�ϣ����˵����¸���Ϊ���湬���Լ���õ�֮�⡣����ܾ�û���������ˣ������϶������˻ҳ���" );
    

/*****************************************************
        set("exits", ([
                "south" : __DIR__"fangzhenqiao",
        ]));

********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
