//wuwujing.h

//Sample for room:  ���������޾�
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_wuwujing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���������޾�");

			
	add_door("�������嶼��̨", "�������嶼��̨", "���������޾�");
	add_door("�����´ȱ�Ժ", "�����´ȱ�Ժ", "���������޾�");
	add_door("���������ĸ�", "���������ĸ�", "���������޾�");
	add_door("�������껨Ժ", "�������껨Ժ", "���������޾�");

	set("long","һƬˮ�ؾ�����ǰ��һ������ľ�ź�����ϣ����䵹Ӱǡ��һԲ��ӳ�ſ����ˮ�棬ʹ�����������������·���ᵽ������֮Դ������֮�������С�");
    

/******************************************************************************
        set("outdoors","tianlongsi");
        set("exits", ([
            "north": __DIR__"yaotai",
            "south": __DIR__"qingxinge",    			
            "west" : __DIR__"cibeiyuan",
            "east" : __DIR__"yuhuayuan",
        ]));
******************************************************************************/
};


ROOM_END;
