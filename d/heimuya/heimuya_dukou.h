//dukou.h

//Sample for room: ���Ŷɿ�
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_dukou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���Ŷɿ�");

   	add_door("�ƺ�2", "�ƺ�2", "��ľ�����Ŷɿ�");
	add_door("�ƺӻ�����ԭ", "�ƺӻ�����ԭ", "��ľ�����Ŷɿ�");		
	add_door("��ľ�»���·4", "��ľ�»���·4", "��ľ�����Ŷɿ�");
	add_door("��ɽ����ʯ���", "��ɽ����ʯ���", "��ľ�����Ŷɿ�");

	
				
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
	add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}

	set("long", "�ɿ�ǰ������ӿ���ȵĻƺ�(he)�ˡ�������������ɳ���£�������������ɴ������������ڲ����д��У���Ϊ���ա����˻ƺӣ����������ˡ�");
    

/*****************************************************
    set("exits", ([
        "northeast" : __DIR__"road4",
    ]));
    set("item_desc", ([
        "he" : "һҶС��ҡ�ڲ����ض���ǰ�У���(yell)һ���Կ���\n",
    ]));
********************************************/
};


ROOM_END;
