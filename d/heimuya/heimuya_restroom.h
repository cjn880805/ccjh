//restroom.h

//Sample for room: ��Ϣ��
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_restroom);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ϣ��");


	add_door("��ľ�³ɵµ�", "��ľ�³ɵµ�", "��ľ����Ϣ��");

	set("long", "�����Ǽ���Ϣ�ң��������Ŵ󴲡�������˯���ǳ������û���ܴ��š����������ɵĳ��ȡ� ");
    set("sleep_room", 1);
    set("no_fight",1);
    set("no_steal",1);
    

/*****************************************************
  set("exits",([
      "east" : __DIR__"huoting",
  ]));

********************************************/
};


ROOM_END;
