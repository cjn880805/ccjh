//house.h

//Sample for room: ��ľ������
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_house);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ������");
	
	add_npc("heimuya_zhang1");       //add by zdn 2001-07-20
	add_npc("pub_xiangke");


	add_door("��ľ�³ɵµ�", "��ľ�³ɵµ�", "��ľ������");

	set("long", "����һ�����ŵ�С�ᣬһ���ű���ŵ�һ��Ũ���Ļ��㡣���й���һ����Ů���ͼ��ͼ�л��������װ��Ů����Ŀ���⣬�������ס����ﻹ��һ�Ų輸���������ӣ������������廨���棬������һ�ȶ�����ͨ������� ");
    
    set("valid_startroom", 1);

/*****************************************************
  set("exits",([
      "west"      : __DIR__"huoting",
  ]));
//  set("objects", ([
//      __DIR__"npc/xifang" : 1,
//  ]));                                                    
  
********************************************/
};


ROOM_END;




