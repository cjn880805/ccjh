//changlang.h

//Sample for room: ��ľ�³���
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_changlang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ�³���");

	//add npcs into the room
	add_npc("heimuya_jiaotu");

	add_door("��ľ�°׻���", "��ľ�°׻���", "��ľ�³���");
	add_door("��ľ�°׻��ô���", "��ľ�°׻��ô���", "��ľ�³���");

	set("long", "�����ǰ׻��õĳ��ȡ�����һƬ�Ǽ��������Ӹձ�ϴ��һ������غ�ʬ���в��̶á� ");
    

/*****************************************************
  set("exits",([
      "east" : __DIR__"dating2",
      "south" : __DIR__"baistep2",
  ]));
  set("objects",([
     __DIR__"npc/jiaotu"   :1,
  ]));
********************************************/
};


ROOM_END;
