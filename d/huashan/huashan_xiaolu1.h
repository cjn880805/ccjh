//xiaolu1.h

//Sample for room: ��ɽСɽ·
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_xiaolu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽСɽ·");
	
	add_npc("pub_youke");          //add by zdn 2001-07-17


	add_door("��ɽ��Ů��", "��ɽ��Ů��", "��ɽСɽ·");
	add_door("��ɽС��", "��ɽС��", "��ɽСɽ·");

	set("long", "�����ǻ�ɽ��һ��Сɽ·�����ƽ�Ϊƽ�������������ط���ô�վ���������������ܾ����ĵģ�������߽���һ��������Դ��");  
    
 
/*****************************************************
      set("exits",([  
          "southwest"     : __DIR__"yunu",
          "northeast"     : __DIR__"xiaolu2",
      ]));
********************************************/
};


ROOM_END;
