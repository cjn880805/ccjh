//changlang2.h

//Sample for room: ��ľ�³���2
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_changlang2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ�³���2");
	
	add_npc("heimuya_jiaotu");  //add by zdn 2001-07-20


	add_door("��ľ��������", "��ľ��������", "��ľ�³���2");
	add_door("��ľ�������ô���", "��ľ�������ô���", "��ľ�³���2");

	set("long", "�����Ƿǳ����ɵĳ��ȡ�����ȴûʲô��������ϱ��������õĴ����� ");
    set("no_fight",0l);
    set("no_steal",0l);
    
 
/*****************************************************
  set("exits",([
      "north" : __DIR__"chlang1",
      "south" : __DIR__"qing",
  ]));			   
  set("objects",([
      __DIR__"npc/shinu1"   :1,
  ]));
********************************************/
};


ROOM_END;
