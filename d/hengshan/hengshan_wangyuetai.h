//wangyuetai.h

//Sample for room: ��ɽ����̨
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_wangyuetai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ����̨");


	add_door("��ɽף�ڵ�", "��ɽף�ڵ�", "��ɽ����̨");

    set("long","  ����̨��ף�ڵ��һ���ʾ�ʯ��ÿ��ҹ������µ��գ��������̱��֣�����������ԣ�������ɫ����ӳ�Ͱ���Ⱥ�塣��ʱ '��Ȼ�������ʮ���壬����������У�ʼ���·��޴���Ҳ��' ǰ�������ʫ: �˼������ѽԾ����˵������δ�͡� " );
    

/*****************************************************
        set("exits", ([ 
           "southup"    : __DIR__"zhurongdian",
        ]));
********************************************/
};


ROOM_END;
