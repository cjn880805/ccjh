//mingwang_jian.h ������
//�ز� 2002-5-11

EQUIP_BEGIN(CImingwang_jian);


virtual void create(int nFlag = 0)		
{
	set_name( "������");	

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(20000);		//set item weight

	set("unit", "��");
	set("long", "����һ���ܽ�������ȫ��Ϊ�����������������ϸ����Ű�Ҷ�����������м������ġ�����������������Ѫ������ͨΪ��ɫ���Ե÷������޹��죬��ȴ������ħ�ϵ�ʥ����");
	set("material", "steel");
	set("weapon/strength", 10);
	set("wield_msg",  "ֻ��$N�����������ղ���������Ȼ�����б仯��һ���û��Ƶ���������" );
	set("unwield_msg",  "$NͻȻ��ͷһ������֪����ħ���֣�æ������������������ҵ�ϡ�" );

	set("apply/damage", random(100)+230);					//set the modifiers of attribute
 
};

EQUIP_END;

//last, register the item into ../server/ItemSetup.cpp



