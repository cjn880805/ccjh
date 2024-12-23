//gaitou.h
//����ͷ
//Lanwood 2001-03-17

EQUIP_BEGIN(CIgaitou)

virtual void create(int nFlag = 0)		
{
	set_name("����ͷ", "gai tou");
           
	set("wield_position", WIELD_HEAD);	
 	set_weight(2000);	

	set("apply/name", "������");
	set("apply/title", "���ߵ�");
	set("apply/id", "marry girl");
	set("apply/long", "����һ���ȴ��ɷ�Ϊ���ҿ���ͷ���ߴ��������ӡ�");

	set("long",	"���Ǹ�������ר�õĴ���ͷ��");
	set("unit", "��");
	
	set("value",500);
};

virtual int Do_Action(int nAct, CChar * me = NULL)
{
	CContainer * owner =  environment();
	
	if(!owner) return 0;

	if(nAct == DO_WIELD && Query(CAN_EQUIPPED))
	{			
		if(! Do_Wield()) return 0;
		//owner->set_temp("apply/icon", query("apply/icon"));
		owner->UpdateMe();
		return 1;
	}
	else if(nAct == DO_UNWIELD)
	{
		if(! Do_UnWield()) return 0;
		owner->delete_temp("apply/icon");
		owner->delete_temp("apply/title");
		owner->UpdateMe();
		return 1;
	}

	return CEquip::Do_Action(nAct, me);
}

EQUIP_END;
