//bighouse2.h

//Sample for room: ��ɽ�����������
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRHuaShanCuen_bighouse2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�����������");
	
	add_npc("pub_lady3");       //add by zdn 2001-07-14

	add_door("������ǰ��", "��ɽ�������ǰ��", "��ɽ�����������");

  	set("long","������һ�����ң������м���һ�Ŵ󴲣����ϵı����Ȼ�ǳ�еģ�����������������Լ�������ʮ�ֿ̱���������ż�ֻľ���ӣ�ǽ������һֻ�����(cabinet)��" );
    

/*****************************************************
        set("exits", ([
            "west" :"/d/village/bighouse1",
        ]));
*****************************************************/
};


ROOM_END;
