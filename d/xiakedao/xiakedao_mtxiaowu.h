//mtxiaowu.h

//Sample for room: ���͵�ľ��
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_mtxiaowu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵�ľ��");
	
	add_npc("pub_tongzi");        //add by zdn 2001-07-20


	add_door("���͵�Ħ����", "���͵�Ħ����", "���͵�ľ��");

	set("long", "������һ����С��ľ�ݣ����з���һЩ���߰���ļҾߣ�ǽ�Ǳ߻���һ�����õ�С������һ��Ӣ��������������������ȥ���ƺ���ʲô���£���ʱ�ķ���������̾......" );
    

/*****************************************************
       set("exits", ([
           "west" : __DIR__"mtdating",
       ]));
       set("objects",([
           __DIR__"npc/shizhongyu" : 1,
       ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp