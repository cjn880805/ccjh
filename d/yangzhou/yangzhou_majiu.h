//majiu.h

//Sample for room: ���
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRYangZhou_majiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���");

	//add npcs into the room
//	add_npc("pub_mafu");
//	add_npc("animal_zaohongma");
//	add_npc("animal_huangbiaoma");
//	add_npc("animal_ziliuma");


	add_door("���ݿ͵�", "���ݿ͵�", "�������");

    set("outdoors", "city");
    set("no_fight", "1");
    set("no_beg", "1");
    
/*****************************************************
      set("objects", ([
               __DIR__"npc/zaohongma": 1,
               __DIR__"npc/huangbiaoma": 1,
               __DIR__"npc/ziliuma": 1,
               __DIR__"npc/mafu": 1,
      ]));
      set("item_desc", ([
          "paizi": @TEXT
������ֻҪ�����һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ������:  ridebj
          ���ݳ�:  ridesz
          ���ݳ�:  ridehz
          ���ݳ�:  ridefz
          �����:  ridedl
          ������:  ridexy
          ���ǳ�:  rideyd
          ������:  rideyl
          ��ɽ��:  ridefs
          ����ɽ:  rideem

TEXT]));
      set("exits",([ 
          "west"      : __DIR__"kedian",
      ]));
********************************************/
};


ROOM_END;
