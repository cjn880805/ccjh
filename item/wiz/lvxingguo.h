//lvxingguo.h

//Sample for ITEM »�ǹ�
//coded by Fisho
//data: 2000-11-15


FOOD_BEGIN(CIlvxingguo);


virtual void create(int nFlag = 0)	
{
	set_name( "»�ǹ�");	
	set("unit", "��");
	set("long", "�Ĳ����ӹ���»��Ϊ»��");
    set("no_give", "�ô󷽵���ѽ��������Ұɣ�");
    set("value", 0l);
	set("no_steal", 1);
	set("no_beg", 1);
    set("no_put", 1);
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���");

};

virtual int do_use(CChar * me, CContainer * target)
{
	me->add_temp("apply/per",8);
	message_vision( "$N���������ˣ�һ������»�ǹ�����ʱ�ݹ����.������ˡ�" , me);
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



