//shouxingtao.h

//Sample for ITEM ������
//coded by Fisho
//data: 2000-11-15


FOOD_BEGIN(CIshouxingtao);


virtual void create(int nFlag = 0)	
{
	set_name( "������");	
	set("unit", "��");
	set("long", "���Ǽ��ϼ����̣��˳���֮������Ϊ����");
    set("no_give", "�ô󷽵���ѽ��������Ұɣ�");
    set("value", 0l);
	set("no_steal", 1);
	set("no_beg", 1);
    set("no_put", 1);
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���");

};

virtual int do_use(CChar * me, CContainer * target)
{
	me->add("max_hp", 888);
	me->add("eff_hp", 888);
	me->add("hp", 888);
	message_vision( "$N���ڰ����е������ҿи����⣬����ȫ��һ����.Ѫ�����ǡ�" , me);
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



