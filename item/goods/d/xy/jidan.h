//jidan.h ��ң�����������
ITEM_BEGIN(CIjidan)

virtual void create(int nFlag = 0)		
{
	set_name("����", "ji dan");
	set("long",	"���µĵ��ͽм�����");
	set("unit", "֧");
	set_weight(1000);
	set("value", 1);
	call_out(do_die, 850);	
};

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}

ITEM_END;




