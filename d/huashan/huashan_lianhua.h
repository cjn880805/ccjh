//lianhua.h

//Sample for room: ��ɽ������
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_lianhua);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������");

	add_door("��ɽ������ɽ��", "��ɽ������ɽ��", "��ɽ������");

	set("long", "̫�����壭���������壬Ҳ��ܽ�ط壬�嶥��һ���ʯ��״���������������ۡ��ô��ɴ˵������������¶��ͣ�����ǧ�𣬵���Զ�����ش�çç��μ�����ˮ����������嶥��ʯ����ժ��ʯ����ȡ���ֿ�ժ�ǳ���֮�⣬��״����֮�ߡ�");  
    
 
/*****************************************************
        set("exits", ([  
             "eastdown" : __DIR__"chengxiang",
        ]));
********************************************/
};


ROOM_END;
