//temple1.h

//Sample for room: ��̳��
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRHuaShanCuen_temple1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��̳��");
	
	add_npc("pub_dibao");          //add by zdn 2001-07-14


	add_door("��ɽ��", "��ɽ��", "��ɽ����̳��");

  	set("long","����һ��ʮ���ƾɵ�С�����﹩������������̳�������Ѿ��ܲ����ˣ�����Ҳ���˺ܶ೾�����������кܾ�û������������ˡ���Ŵ���ƶ����̫�ã��Ѳ��ټ���춲���ү�����������ˡ����������ǽ���и����˶�ߵĶ�(hole)��" );
    

/*****************************************************
        set("exits", ([ 
            "southwest" : __DIR__"nwroad1",
        ]));
        set("item_desc", ([
                "hole": "��������󶴱����俪���ã����Ǳߺ����и�С���ӡ�\n"
        ]) );
********************************************/
};


ROOM_END;
