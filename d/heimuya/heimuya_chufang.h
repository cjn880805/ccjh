//chufang.h

//Sample for room: ��ľ�°׻��ó���
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ�°׻��ó���");

        add_npc("pub_cunfu");     // add by zdn 2001-07-14

	add_door("��ľ�°׻���", "��ľ�°׻���", "��ľ�°׻��ó���");

	set("long", "����ʥ���õĳ�����һλ������Ů������Ц���������������֬��������ǽ������һ����Ŀ������(note)��");

/*****************************************************
  set("exits",([
      "west" : __DIR__"chitang",
  ]));
  set("item_desc",([
      "note" : "��������Ů�˸������ջ�ˮ��----->����Ⱥ��\n",
  ]));

  set("objects",([
      __DIR__"npc/shinu" : 1,
      __DIR__"obj/tea" : random(6),
      __DIR__"obj/sherou"  : random(4),
  ]));
//  
********************************************/
};


ROOM_END;
