//tongyuangu.h

//Sample for room: ��ɽͨԪ��
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_tongyuangu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽͨԪ��");
	add_npc("hengshan_dingyueshitai");

	add_door("��ɽ������", "��ɽ������", "��ɽͨԪ��");

    set("long","ͨԪ�ȹ´����Է��£��ഫΪ�Ź��ϳ���ǰ�޵�֮�������������� 'ͨԪ' ������Ҳ�ͳ���ͨԪ�ȡ�  " );
    

/*****************************************************
        set("exits", ([ 
           "eastup"  : __DIR__"guolaoling",
        ]));
********************************************/
};


ROOM_END;
