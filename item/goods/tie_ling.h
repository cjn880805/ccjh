ITEM_BEGIN(CItie_ling)

virtual void create(int nFlag = 0)		
{
	set_name("������", "chongyang ling");
	set_weight(100);
	set("unit", "��");
    set("long", "����һ������ͨ�����������������ơ� �ɵ�������ǩ��������·Ӣ���빬����");
	set("value", 100);
	set("material", "iron");

	call_out(do_dest, 1800);
};

static void do_dest(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}

ITEM_END;
