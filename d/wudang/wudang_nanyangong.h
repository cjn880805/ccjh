//nanyangong.h

//Sample for room: ���ҹ�
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWuDang_nanyangong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ҹ�");

	add_door("�䵱ʯ��", "�䵱ʯ��", "�䵱���ҹ�");
	add_door("�䵱���ҹ���̨", "�䵱���ҹ���̨", "�䵱���ҹ�");

    

/*****************************************************
      set("exits",([ 
          "out"    : __DIR__"shizhu",
          "southup": __DIR__"gaotai",
      ]));
      set("item_desc",([
          "��������" :       (: look_xiang :),
      ]));
*****************************************************/
};


ROOM_END;
