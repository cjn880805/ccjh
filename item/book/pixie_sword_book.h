ITEM_BEGIN(CIpixie_sword_book);

virtual void create(int nFlag = 0)		
{
	set_name( "��а����");	

 	set_weight(600);		

	set("unit", "��");
 	set("long", "����һ����а����,��������ϰ��а�����������Ȿ�鲢��Ҫ���Թ�, ���е�֡�");
	set("value",  1000 );
	set("material", "paper");
	set("skill/name","pixie_sword");
	set("skill/exp_required",  10000);
	set("skill/sen_cost",   30 );	
	set("skill/difficulty", 30 );
	set("skill/max_skill",  100);
	set("skill/min_skill", 0l );  
	

};

ITEM_END;
