//chaoyang.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_chaoyang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	add_npc("yinchang_ailaozhe");	
	add_npc("huashan_gao_laozhe");	

	add_door("��ɽ������С·2", "��ɽ������С·2", "��ɽ������");

	set("long", "������ǻ�ɽ�Ķ��壬Ҳ�Ƴ����壬�ǻ�ɽ���ճ��ľ��Ѵ���춴˸���ƺ����Զ������������С�·屳��ɽ�ӡ�С�·�����һСͤ���������ߣ�ͤ����������һ�֣��Ǿ��ǻ�ɽ�����ġ���̨���ˡ����������ϣ�����һ��������ӡ���ഫΪ��������项��ɽʱ�����µģ����ʫ�С�������������ɽ���鲨�����䶫��������ָ����ϹŴ�˵��");  
 
/*****************************************************
        set("exits", ([  
           "westdown" : __DIR__"chaopath2",
        ]));
        set("objects", ([
            CLASS_D("huashan")+"/gao-laozhe": 1,
            CLASS_D("huashan")+"/ai-laozhe": 1,
        ]));
********************************************/
};


ROOM_END;
