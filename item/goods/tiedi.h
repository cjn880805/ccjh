//tiedi.h	

ITEM_BEGIN(CItiedi)

virtual void create(int nFlag = 0)		
{
	    
	set_name("����", "tie di");
	set_weight(500);

	set("unit", "֧");
	set("long", "һ֧�������ɵĳ��ѣ�����ȥ�����쳣��");
	set("value", 10000);
	set("material", "bamboo");
	set("wield_msg", "$N����һ�ӣ������Ѷ���һ֧�ں��͹�����ѡ�");
	set("unwield_msg", "$N��������һת��գ�ۼ�������Ȼ����Ӱ�١�");
	
	set("apply/damage", 50);	
};

ITEM_END;
