//chengdedian.h

//Sample for room: �ɵµ�
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_chengdedian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ɵµ�");
	
	add_npc("heimuya_yang");        //add by zdn 2001-07-20
	add_npc("pub_xiangke");


	add_door("��ľ������ƺ", "��ľ������ƺ", "��ľ�³ɵµ�");

	add_door("��ľ�º���", "��ľ�º���", "��ľ�³ɵµ�");
	add_door("��ľ������", "��ľ������", "��ľ�³ɵµ�");
	add_door("��ľ����Ϣ��", "��ľ����Ϣ��", "��ľ�³ɵµ�");

	set("long", "�����������̽���ƽ�շ���ʩ��ĵط��������޴�����ڵ������λε����򣬴��˶˸���һ��������һ��Ӣ���������ˣ��������𽭺��Ķ������ܵ��ͷ����ͤ�ˣ� ");
    set("valid_startroom", 1);

/*****************************************************
  set("exits",([
      "north" : __DIR__"huoting",
      "westdown":__DIR__"up4",
  ]));
  set("objects",([
      __DIR__"npc/dizi" : 2,
      __DIR__"npc/yang"    :1,
  ]));
//   
********************************************/
};


ROOM_END;




