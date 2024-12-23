// Npc.cpp: implementation of the CNpc class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Npc.h"
#include "Globle.h"
#include "../std/FightRoom.h"
#include "Room.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CNpc::~CNpc()
{
	LISTINQUIRY::iterator p;

	for(p = m_listInquiry.begin(); p != m_listInquiry.end(); p++)
		delete p->second;

	m_listInquiry.clear();
}

LONG CNpc::Query(int nAttr)
{
	if( nAttr == IS_NPC )
		return 1;
	
	return CChar::Query(nAttr);
}

//����ж�
int CNpc::Self_Action()
{
	int chance;
	const char * ptr = NULL;

	if( !environment() ) return 0;
	if( ! living(this)) return 0;

	if( ! (chance = is_fighting() ? query("chat_chance_combat") : query("chat_chance")) )
		return 0;

	if( random(100) < chance )
	{
		if(is_fighting())
		{
			//�ж�һ���Ƿ���ս��room
			if(environment()->Query(IS_FIGHTROOM))
				ptr = chat_msg_combat();
			else
				output_error("NPC%s�ڻ���%s�г���ս��״̬��", name(), environment()->name());
		}
		else
			ptr = chat_msg();

		if(ptr && ptr[0])
			MessageVision(this, "chat", ptr);

		return 1;
    }

	return 0;
}

char * CNpc::chat_msg()
{
	return 0;
}

char * CNpc::chat_msg_combat()
{
	return 0;
}

//�ص��ûصĵط�ȥ
int CNpc::return_home(CContainer *home)
{
	if( !environment() || environment() == home )
		return 1;

	if( ! Query(IS_LIVING) ) return 0;	//no return
	double value = 300;		//����5����ս����NPC�Զ���ȥ
	time_t t;
	time(&t);
	t -= (time_t)value;	

	if( is_fighting() && (time_t)query_temp("fight/join_time")>t) return 0;	//is fighting
  
	// Leave for home now.
	message_vision("$N�Ҵ�ææ�뿪�ˡ�", this);
	move(home);
	return 1;
}

void CNpc::create()
{
	
}

//Я�����
CContainer * CNpc::carry_object(const char * obj_name, LONG nAmount, int idx)
{
	CContainer * item;

	item = load_item(obj_name);
	
	if(idx) item->create(idx);

	if(nAmount > 0)
		item->set_amount(nAmount);
	else
		item->set_amount(1);
	/*
	if(item->Query(UNIQUE)
	*/

	item->move(this);
	return item;
}

CNpc * random_npc();

const char * position_npc(CChar * npc)
{
	CContainer * env = npc->environment();
	if(! env) return 0;	//ʧ��
	if(env->query("no_fight")) return 0;	//��ս������
	if(EQUALSTR(env->querystr("area"), "house")) return 0;	//���סլ

	while(env->environment())
		env = env->environment();

	return env->name(1);
}

void reward_tradepro(CChar * me)
{
	//�ȸ���ҽ��н���

	char msg[255];
	LONG exp = me->query("level");
	static char GoodItem[45][40] = 
	{
	"38huoqiang","tiancanbaojia",	"xuantiebishou","fannaomao",
	"liaochengpao","yinguozhu",	"bolanxie","zhangmenhuan",
	"jinhuantoushi","dagoubang",	"ruanweijia","shajiezhi",
	"zidiaopifeng","haoseshan",	"dulonglian","shenshe_staff",
	"yinmopao","btzheng",	"diaojiandai","poliquan",
	"yanshuhua","fengyizhen",	"jinlianxie","kuihuaao",
	"taibaizao","xiantianyu",	"zwsword","xuanwupao",
	"yunshenglv","qinjianhun",	"zijianhun","luoshenjin",
	"linboxie","zueiyupao",	"hanyuzhi","lantiandai",
	"lvzhuxiao","conglinjian",	"cangzuihu","rumengdai",
	"chunjie_ts","buildcorps1","tianmen_map","qunxing_tu","conglinjian",
	};
/*
	char tmp[40];
	int base=7;
	if(me->query("int")>60)
		base++;

	exp = exp * base;

	int count=me->query("tradepro/quest_count");
	
	exp = exp*(5000+base*(count%10))/5000;

	exp = (random(exp) + exp) / 2;

	if(exp>100000)
		exp=random(500)+100000;
*/
	//�����Ӿ�����㹫ʽ 2005��4��11
	int count=me->query("tradepro/quest_count");
	exp=exp*2;
	exp=exp+(exp+me->query("int")*2)*int(count/10+count%10);
	//
	me->add("combat_exp", exp);

	count++;
/*
	int contribute=count*10+random(count);
	int money=count;

	me->add("corps/contribute",contribute);
	me->add("corps/money",money);
*/
	me->FlushMyInfo();
	tell_object(me, snprintf(msg, 255, "$HIC��ϲ������ˡ��̽��������ĵ�%d�����񣬻����%d�㾭�顣", count,exp));
	if(me->query("tradepro/quest_count")%100==0 && me->query("tradepro/quest_count")>99)
	{
		CContainer * good_item=load_item(GoodItem[random(45)]);
		tell_object(me, snprintf(msg, 255, "$HIRͬʱ������%s�Ľ�����", good_item->name(1)));
		good_item->move(me);
	}
	me->del("tradepro");
//	tell_object(me, snprintf(msg, 255, "$HIC��ϲ������ˡ��̽��������ĵ�%d�����񣬻����%s�㾭�飬ͬʱ�����%d��İ��ɹ��׶ȡ�%d��İ��ɲƸ���", count,chinese_number(exp, tmp),contribute,money));
	if(count<=600)
		me->set("tradepro/quest_count",count);
	else
	{
		me->del("tradepro");
		return ;
	}

	static char index1[537][40] = {
		"blade_1","blade_2","cleansword","dadao","zimuzhen",
			"dadao2","dafu","dagger","duanjian","fenshuici","fork","fuchen","futou",
			"hammer","heilongbian",	"hothammer","huaji","huoqiang","jinhua","jinlun",
			"jiujiebian","kandao","kuihuazhen","leizhendang","mandao","panguanbi",
			"putongbishou","qimeigun","qin","qingzugang","qingzuzang","qinqin_sword","ruanjian",
			"senggun","shebian","shenghuo_ling","shezhang","shield","shunvjian","shutonggun","snowsword","sword_1",
			"sword_2","sword_3","tiepipa","tongren","walkingstick","wandao","wodao","xblade",
			"xiao","xiuhua","xuantiesword","yangbian","yaochu","yaoqin","yinlun",
			"yufeng_zhen","yuxiao","yuzhu_zhang","zijin_staff",
			"cloth","pixue","dao_xie","daopaocyan_cloth","female1_cloth","female2_cloth","female3_cloth",
			"female6_cloth","flower_shoe","green_cloth","greenrobe","greyrobe","gunny_shoes","hui_cloth",
			"huwan","huyao","jin","jindai","jinduan","junfu","male1_cloth",
			"male3_cloth","male4_cloth","male6_cloth","male7_cloth","male8_cloth","male_shoe","necklace",
			"ni_cloth","ni_xie","pink_cloth","piqiu","qing_cloth","qingyi","r_jiasha","ring",
			"seng_cloth","seng_xie","sengmao","sengxie","shepi","shoe","shoutao","shuikao","shouzhuo","tiejia",
			"surcoat","test","toukui","white_robe","wuxingfu","xu_cloth","xuan_cloth","y_jiasha","yaodai",
			"yayi_cloth","ycloth","yupei","zhanyi","zhenzhu","tiezhitao","zichoushan","b_jiasha","baguafu",
			"baichou","baipao","bduanqun","beixin","belt","blackcloth","bluecloth","boots","bu_shoes",
			"bupao","c_jiasha","caoxie","changpao","changpao2","cheng_cloth","choupao","cloth2","connie",
			"cuiyu","cycle","cynrobe","dao_cloth","doupeng","dress","feather","fu_cloth",
			"goldring","goupi","guazi","gui_dress","hat","hupi","hushenfu","jade_belt","jinsijia","jjunfu","kenao","lace",
			"linen","liu_dress","magcloth","magua","marry_dress","mini_dress","moon_dress","pink_dress",
			"qi_dress","qun","red_dress","ruanwei","scarf","sha_dress","shoes","shoupa","skirt",
			"shudai","tduanqun","tiebeixin","tiehuwan","tiehuyao","tieshou","tongqun","ttoujin","wchangqun","wcloth","wdahui",
			"whitecloth","whitecloth1","xian_cloth","xiaoao","xiu_cloth","xiu_scarf","yan_dress","zi_dress","mask",
			"baihe","baozi","duanchang","gourou","guijia","guiyuan","heiyugao","honghua",
			"jinchuang","jitui","jiudai","jindan","kaoya","marz","menghan_yao","mizhitianou","moyao",
			"nverhong","peanut","putizi","qingdan","qingke_m","renshen",
			"shedan","shedangao","sherou","turou","x_drug","xionghuang",
			"yadan","yangxin","yuchandan","zongzi","zhutou","zhujingchan","yangjing","xiang","gao","egg","dahuan_dan",
			"cha","caomei","cake","luobo","caogeng","jingxin_san","honey",
			"book_paper","parry_book","hand_book","strike_book","book_stone","dodgebook","force_book","yijing0","book_silk",
			"yijing1","wuji3","wuji2","throw_book","staff_book","staff_book","lbook1","lbook2","yunv_swordb",
			"yunvjing1","lbook3","miaoshou","xuanfeng_book","yijinjing","yunvjing2","lbook3","miaoshou",
			"zhengqi_book","18muou","sword_book1","skin","literateb4","dodgebook","book_iron",
			"cleansword","snowsword","ruanjian","qin","leizhendang","qingzuzang","jinlun",
			"zijin_staff","sword_2","sword_3",
			"zongzi","backleg","yangrou","turou","tofu","puercha","paomo","mizhitianou","mala_doufu",
			"furong_huagu","baozi2","mixian","huotui","hamigua","luobo","geng","gao4","shedan",
			"zaisheng","suanmei","niupidai","changbian","changjian","changqiang","chanzhang",
			"dadao2","feihuangshi","fenshuici","fork","fuchen","futou","gangdao","gangjian",
			"gangzhang","hammer","jiandao","mutang","senggun","shebian","shield","shortblade",
			"wandao","wodao","xiuhua","yuxiao","zheshan","zhubang","b_jiasha","changpao","choupao",
			"dao_cloth","doupeng2","hat","huangshan","hui_cloth","hupi","jiasha","junfu","piqiu",
			"qingyi2","sengmao","seng_cloth","shepi","shoe","shoes","shuikao","tiebeixin","toukui",
			"wchangqun","xian_cloth","map","yadan","xiaren2","shanhu_baicai","rice","nang","liuli_qiezi",
			"kaoyangtui","kaoya","jiaxin_biji","gourou","birddie","basi_shanyao","yezi","yangjing",
			"xueli","suya","yaopin_2","yaopin_1","heiyue_si",
			"suji","mangguo","huotui2","gao","gaoyao","gao3","ping","dadao","gangbiao","heilongbian",
			"jiedao","panguanbi","qimeigun","qin","shezhang","shortsword","shutonggun","tielianzi",
			"tiepipa","tie_gan","tongren","tudao","zijinchui","changpao2","cheng_cloth",
			"daopaocyan_cloth","jindai","jjunfu","ni_cloth","ni_xie","pink_cloth","p_jiasha",
			"yaopin_2","yaopin_1","transfer_tie","zhuguo",
			"baihongjian","bilinzhen","bishou","blade_1","blade_2","cleansword","dadao","zimuzhen",
			"dadao2","dafu","dagger","duanjian","fandog_sword","fenshuici","fork","fuchen","futou","green_sword",
			"green_water_sword","hammer","heilongbian",	"hothammer","huaji","hugesword","huoqiang","jinhua","jinlun",
			"jiujiebian","kandao","kuihuazhen","langyabang","leizhendang","longquansword","mandao","panguanbi",
			"putongbishou","qimeigun","qin","qingzugang","qingzuzang","qinqin_sword","ring_whip","ruanjian","sea_wood",
			"senggun","shebian","shenghuo_ling","shezhang","shield","shunvjian","shutonggun","snowsword","sword_1",
			"sword_2","sword_3","taomujian","tiepipa","tongren","walkingstick","wandao","wodao","wuqing_sword","xblade",
			"xem_sword","xiao","xiuhua","xuantiesword","xuedao","yangbian","yaochu","yaoqin","yinlun","youlongsword",
			"yufeng_zhen","yuxiao","yuzhu_zhang","zijinchui","zijin_staff",
			"38huoqiang","xuantiebishou","dagoubang","shenshe_staff","haoseshan","btzheng","taibaizao","zwsword",
			"lvzhuxiao","conglinjian","newyear","newyear1","century_war","tiancanbaojia","fannaomao","liaochengpao",
			"yinguozhu","bolanxie","zhangmenhuan","jinhuantoushi","ruanweijia","shajiezhi","zidiaopifeng","dulonglian",
			"yinmopao","diaojiandai","xiantianyu","poliquan","yanshuhua","fengyizhen","jinlianxie","kuihuaao","xuanwupao",
			"yunshenglv","zijianhun","qinjianhun","luoshenjin","linboxie","zueiyupao","hanyuzhi","lantiandai","cangzuihu",
			"rumengdai",
	};

	static char index1_1[5][255] =
	{
		"����$HIW%s$COM���ڴ��⣬��ʧ��$HIW%s$COM�����ǰ��գ��鷳���æȥ��һ����ȥ��",
			"$HIW%s$COMǰ�յ������������ģ��ᵽ$HIW%s$COM������ϲ�������������������Ƿ����������һ����ȥ������",
			"�⼸�մ��ԣ�$HIW%s$COM���ڴ����Ѽ�$HIW%s$COM�����п��Ƿ���һ����ȥ��������ͼ��Ϊ��",
			"$HIW%s$COM������һ��$HIW%s$COM�������пգ�������æ������ȥ��",
			"��ǰ����Ӧ��$HIW%s$COMȥѰ��һ��$HIW%s$COM��ȥ����һֱ���ÿ�Ͼ�����ջ�������æѰ�٣���һ����ȥ��",
	};

	static char index2[5][255] =
	{
		"�þò���$HIW%s$COM�ˣ��鷳��ȥ�ҵ���˵����������",
			"$HIW%s$COMǰ��ʱ�����������ݷã���һֱ��ûʱ��ط�,����������ȥ��������",
			"$HIW%s$COM�Ѿ�ʧ�ٺܾ���,���Ƿ��п�����ȥ�������������������ô���ˣ�",
			"�Һ�����$HIW%s$COM�����ܲ��������͸����Ÿ������������ʺ�����",
			"ǰ��ʱ���Ҵ�Ӧ$HIW%s$COMȥ��ɽ��ˮ�ģ���һֱæ���������˵��������пգ�����һ������С�",
	};

	static char index3[5][255] =
	{
		"����ǰ$HIW%s$COM��ȫ�ұ�$HIW%s$COMɱ�ˣ���������������",
			"$HIW%s$COM���ֳ�������ڽ�������ɱ�޹���$HIW%s$COMɱ�ˣ�������ȥ����Ϊ���ֳ�һ�󺦡�",
			"$HIW%s$COM������Ϣ��$HIW%s$COM�ǽ��������������ɱ�������Ϳ���������ȡһ�ʻ��졣",
			"$HIW%s$COM�ĵ��ӣ������߽���ʱ�����$HIW%s$COM�����ˣ�������ȥɱ������Ϊ������",	
			"��ǰ������Ӧ$HIW%s$COM��Ϊ��ɱ��$HIW%s$COM����ȥ�׼���������ҹ���ȫʧ����������æ��",
	};

	static char index4[5][255] =
	{
		"ǰ��$HIW%s$COM�����¹���$HIW%s$COM͵�ˣ���ȥ����ץ���Ǹ�С͵��",
			"$HIW%s$COM����ͨ��$HIW%s$COM��������ȥץ������",
			"$HIW%s$COM������������˭Ҫ����$HIW%s$COM�鰸���������͡�",
			"$HIW%s$COM�ĳ�Ҷ��$HIW%s$COM���ڽ���������Ϊ�ˣ��������æ����ȥץ��",	
			"�ҵ�����$HIW%s$COMǰ��ʱ����Ϊɢ��������Ʀ$HIW%s$COM����һ�٣�����ץס�Ǹ���Ʀ������ȥ��",
	};

	static char index5[5][255] =
	{
		"����ǰ$HIW%s$COM��$HIW%s$COM�����ˣ���������ȥ����ά���ΰ���",
			"����Ϣ����$HIW%s$COM����������$HIW%s$COM���ΰ���������ȥ����������Ѳ�߼��졣",
			"$HIW%s$COM���ڵ�$HIW%s$COM��������¼��ܶ࣬�������Ǵ���������ά������",
			"$HIW%s$COM��ȥ$HIW%s$COM���������ѣ����������������ȫ���������ȥ��һ��Ѳ�߰ɡ�",	
			"������Ӧ$HIW%s$COM����������$HIW%s$COMһ�����ΰ��������û����Ͼ��������������æ��",
	};

	static char index6[16][20] = 
	{
		"����ɽ��",	"����μ�",	"������", "ؤ��","��Ĺ��", "��ɽ��","���չ�", "����",
			"ȫ���","������","������","�һ���","�䵱��","��ң��","������","ѩɽ��",
	};

	static char index6_1[5][255] =
	{
		"���$HIW%s$COM��������ջ��$HIW%s$COM�ĵ��Ӵ��ˣ�����ȥ������������",
			"$HIW%s$COM�����ñ�$HIW%s$COM��ȥ�ˣ�������Ƕ��в��ϣ�����ֽ�ѵ�����¡�",
			"��ǰ����Ӧ��$HIW%s$COM��Ϊ�����ֽ�ѵ�����˵�$HIW%s$COM���������û��ʱ�䣬��������æ��",
			"$HIW%s$COM�ų�������$HIW%s$COM�������֮�����ɾ����¡�˭��ȥɱһ�ӰٵĻ����������͡�",
			"�⼸��$HIW%s$COM�ĵܵܣ�·����ɽ��$HIW%s$COM���ˣ�������ȥ��ѵ�����¡�",	
	};

	static char index7[5][255] =
	{
		"$HIW���ʹ��$COM��ȥ���ڣ���Ҫ$HIW%s(%s)$COM��æ����������������",
			"��˵$HIW���ʹ��$COM��ȥ̩ɽѰ��������Լ$HIW%s(%s)$COMһ��ȥ���������æ֪ͨһ����",
			"$HIW���ʹ��$COMҪȥ̸�У�Ҫ�ټ�$HIW%s(%s)$COM������û�ҵ����鷳��ȥ��һ�¡�",
			"$HIW���ʹ��$COM��Ҫ��$HIW%s(%s)$COMһ��ȥ���ʴ�������������ȥ֪ͨ����",	
			"��ǰ������Ӧ$HIW���ʹ��$COM�������ҵ�$HIW%s(%s)$COM������������Ͼ�����������æ��",
	};

	static char index8[5][255] =
	{
		"$HIW%s$COM��Ҫ�������ı��ڣ�������Ŀǰ��״�����������$HIW%s %d$COM�㷽�ɣ���Ҫȥ��æ��",
			"��˵$HIW%s$COM����������ʿ����������ǳ����ϣ���������$HIW%s %d$COM�㣬�㾡��ȥ��߰ɡ�",
			"$HIW%s$COM������Ϣ����Ҫ��һ���ϻ��ˣ��������ڱ������$HIW%s %d$COM�㣬����Ҫȥ��",
			"���$HIW%s$COM�����������̩ɽȡ�ر�������$HIW%s$COM������������Ŭ�����$HIW%d$COM�㡣",	
			"$HIW%s$COM��Ҫ��Ϊ��ɱ�������˵Ķ���������Ŀǰ������������������$HIW%s %d$COM�㣬�����㾡��ȥŬ����",
	};

	static char index9[5][255] =
	{
		"���$HIW%s$COM���ھ�����һֱ���ã�����ȥ���ҵ������ϣ����Ұ������",
			"$HIW%s$COM���ֳ�������ʱ��ǿ����ɱ���鷳��ȥ�����ֳ������δ��ɵ���Ը�������ڳ��������һ�ˣ���",
			"$HIW%s$COM������Ϣ��˭���ڽ��찲ȫѺ��һ�ڣ��Ϳ���ȥ������ȡһ�ʻ��졣",
			"$HIW%s$COM���ڳ������ˣ������ڼ���ȥ�Ҹ��书�˵õ���ʦ����֪����������",	
			"��ǰ������Ӧ$HIW%s$COM������ȥ��һ���ڣ���������޷�������������æ��",
	};

	static char index10[5][255] =
	{
		"ǰ����$HIW%s$COM��ȫ����ɽ���������գ��Һñ�$HIW%s$COM�Ĵ���$HIW%s$COM���ȣ�������Ҳ�˵�����÷ɽ���ף�����ȥ��������",
			"$HIW%s$COMס��$HIW%s$COM�ĺ���$HIW%s$COM����������կ��������ʽΣ����������ȥ��ȥ��æ��ȷ������Ȼ����",
			"��˵$HIW%s$COM����������������ס��$HIW%s$COM������Ӣ��$HIW%s$COM���������ȥ��æ����̫���ˡ�",
			"�ҵĺ���$HIW%s$COMһλ͵�ܵ�$HIW%s$COM���İ��ĵ���$HIW%s$COM��÷ɽ�߹���ס�������㱣��ƽ����",	
			"����Ӧ���ҵĺ���$HIW%s$COM������������������$HIW%s$COM�����$HIW%s$COM��������ҹ���ȫʧ����������æ��",
	};

	static char index11[5][255] =
	{
		"���$HIW%s$COM���µ꿪�ţ���������$HIW%d$COM�����ӹ�ȥ��лл����ô���������ҡ�����Ǯ����ȵ��ţ������ٰ�ʮ����Ҿͻ��㡣",
			"$HIW%s$COM�����ù�ˣ�ȫ���ҵ�����һ�ն��⣬���ڼ�ʮ�������ϣ�������������$HIW%d$COM�����ӹ�ȥ������Ǯ����ȵ��ţ�Ҫ���˰ٰ�ʮ����Ҿͻ��㡣",
			"$HIW%s$COM������������ڽ��ٿ����Դ�ᣬ���ҿ��ǲ������������$HIW%d$COM�����ӹ�ȥ�������ްɡ�����Ǯ����ȵ��ţ��ٰ�ʮ����Ҿ��ܹ��˾ͻ��㡣",
			"ǰЩ����$HIW%s$COM����������˵����ͷ�ܽ����������æ���ϸ�$HIW%d$COM����������ȥ������Ǯ����ȵ��ţ������ٰ�ʮ�����������еĻ��ͻ��㡣",	
			"��ǰ������Ӧ$HIW%s$COM������$HIW%d$COM�������ӣ���������������һ����ȥ������Ǯ����ȵ��ţ����ϸ��ٰ�ʮ��ĵ��ҵ�˽��Ǯ�ܹ��˾ͻ��㡣",
	};

	static char index12[5][255] =
	{
		"����ǰ$HIW%s$COM�����ҵ������鷳���������$HIW%s$COM�͹�ȥ���Ա��ҵ�л�⡣",
			"ǰЩ����$HIW%s$COM�Ķ��ӣ��������ҵ�$HIW%s$COM���ҿɲ���������ң��������æ��ȥ��",	
			"$HIW%s$COM������Ϣ������$HIW%s$COM������ͷ�����У�������������ȥ��",
			"�������$HIW%s$COM�Ķ�������������һ�ְ�������ȱ$HIW%s$COM����������ȥ������",	
			"��ǰ������Ӧ$HIW%s$COM����$HIW%s$COM��ȥ�ģ������ʱ�乫��æ����������æ��",
	};

	static char index13[32][20] = 
	{
		"С����","��Ҷ��","�Ǻ�«","֥����","��������",	"����¶","����","����",	
		"����ͷ","ţ���","��Ԫ��","�����","������","�ٻ��۾���","��Ѫ��","�ӹ�ɢ",
		"������¶","��ת����","����������","�󻹵�","��͢�ط�","��Ҷһ֦","�ϻ�����","ʯ����", 
		"����ӡ","����������","����","�߽�","һҶ","����","ʯέ","����",
	};

	static char index13_1[5][255] =
	{
		"ǰ����$HIW%s$COM�������˵���ռ�$HIW%d$COM�ݵ�$HIW%s$COM�����������ҵ���",
			"$HIW%s$COMҪ��һζ��ҩ��ҩ���ﻹȱ$HIW%d$COM��$HIW%s$COM��������ȥ�һ����͸�����",
			"$HIW%s$COM���о�һ���ط�����Ҫ$HIW%d$COM�ݵ�$HIW%s$COM������ȥ���������",
			"$HIW%s$COM�������˺ܶ�����ȥ���ҳԷ����ȱ����$HIW%d$COM�ݵ�$HIW%s$COM�����������ȥ������",	
			"��Ӧ�й�$HIW%s$COM��Ϊ������$HIW%d$COM�ݵ�$HIW%s$COM�����������Ͼ������������æ���������",
	};

	static char index14[5][255] =
	{
		"ǰ����$HIW%s$COM�������˵����ɱ�ֳ���$HIW%s$COM�Ļ������������ҵ���",
			"$HIW%s$COMҪд���������ǣ������ﻹȱ��$HIW%s$COM�Ļ��񣬷�����ȥ�һ�����",
			"��˵$HIW%s$COM��Ľ$HIW%s$COM�ܾã��������һ�����Ļ�������ȥ����������",
			"$HIW%s$COM�Ľ���ʮ��������Ψ��ȱ����$HIW%s$COM�Ļ������ܲ��������ҵ���",	
			"�Ҵ�Ӧ��$HIW%s$COM��Ϊ���ҵ�$HIW%s$COM�Ļ��񣬿�����ʼ�ն��Ҳ�������������æ��",
	};

	//�ٸ���Ұ�����һ������
	CNpc * npc;
	CContainer * env;
	CContainer * item_quest;
	CContainer * tradepro_item;
	CMapping * enemy;
	CRoom * r;
	int i;
	const char * area;
	//���ȡһ��NPC�ĳ���
//	while()
	for(i=0;i<10000;i++)
	{
		npc = random_npc();
		
		if(! npc ) continue;
		if(! living(npc)) continue;	//���NPC�첻���ˡ�
		if(DIFFERSTR(npc->querystr("race"), "����") ) continue;	//������NPC
		if(npc->query("no_kill")) continue;	//��һ����Ҳ������ҵ����������
		if(npc->query("mfnpc_lvl")) continue;	//������ɽ���������
		if(npc->query("no_talk")) continue;	//���NPC����������
		if(npc->query("no_huan")) continue;	//���NPC����������
		
		env = npc->environment();
		
		//�����ж�NPC���µķ�λ
		area = position_npc(npc);
		if(! area ) continue;	//���NPCû�л���
		if(! area[0]) continue;	//���NPC����ҷ������ս���С�
		if(EQUALSTR(env->querystr("area"), "fight") ) continue;	//���NPC����ҷ������ս���С�
		if(EQUALSTR(env->querystr("area"), "Ұ��") ) continue;	//���NPC��Ұ�⡣
		if(env->query("renwu") ) continue;	//���NPC����������ķ����С�
		break;
	}
	
	int index=random(14)+1;
	if(index==5 || index==7)
		index=1;
	me->set("tradepro/quest_npc_id",npc->querystr("id"));
	me->set("tradepro/quest_npc_name",npc->querystr("name"));
	me->set("tradepro/quest_npc_area",env->querystr("name"));
	me->set("tradepro/index",index);

	double value = 1800;		//30����
	time_t t;
	time(&t);
	t += (time_t)value;	

	me->set("tradepro/quest_time",t);

	switch(index)
	{
	case 1://����
		if(me->query("tradepro/quest_count")>300)
			item_quest=load_item(index1[random(537)]);
		else
			item_quest=load_item(index1[random(300)]);
		me->set("tradepro/quest_item_name",item_quest->querystr("name"));
		me->set("tradepro/quest_item_id",item_quest->querystr("id"));
		tell_object(me, snprintf(msg, 255, index1_1[random(5)], me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_item_name")));
		break;
	case 2://����
	case 3://ɱ��
	case 4://ץ��²
	case 10://����ĳNPCһ��ʱ�䲻��ɱ
	case 14://�滭NPC����
		//ָ����������NPC
		for(i=0;i<10000;i++)
		{
			npc = random_npc();
			
			if(! npc ) continue;
			if(! living(npc)) continue;	//���NPC�첻���ˡ�
			if(DIFFERSTR(npc->querystr("race"), "����") ) continue;	//������NPC
			if(npc->query("no_kill")) continue;	//��һ����Ҳ������ҵ����������
			if(npc->query("mfnpc_lvl")) continue;	//������ɽ���������
//			if(npc->query("no_talk")) continue;	//���NPC����������
			
			env = npc->environment();
			
			//�����ж�NPC���µķ�λ
			area = position_npc(npc);
			if(! area ) continue;	//���NPCû�л���
			if(! area[0]) continue;	//���NPC����ҷ������ս���С�
			if(EQUALSTR(env->querystr("area"), "fight") ) continue;	//���NPC����ҷ������ս���С�
			if(EQUALSTR(env->querystr("area"), "Ұ��") ) continue;	//���NPC��Ұ�⡣
			if(env->query("renwu") ) continue;	//���NPC����������ķ����С�
			break;
		}
		me->set("tradepro/quest_killnpc_id",npc->querystr("id"));
		me->set("tradepro/quest_killnpc_object_id", npc->object_id());
		me->set("tradepro/quest_killnpc_name",npc->querystr("name"));
		if(index==2)
			tell_object(me, snprintf(msg, 255, index2[random(5)], me->querystr("tradepro/quest_npc_name")));
		else if(index==3)
			tell_object(me, snprintf(msg, 255, index3[random(5)], me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_killnpc_name")));
		else if(index==4)
			tell_object(me, snprintf(msg, 255, index4[random(5)], me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_killnpc_name")));
		else if(index==10)
		{
			npc->set("ok",1);
			value = 300;		//5����
			time_t clock;
			time(&clock);
			clock += (time_t)value;	
			me->set("tradepro/quest_killnpc_time",clock);
			me->set("tradepro/quest_killnpc_id",npc->object_id());
			me->set("tradepro/quest_killnpc_area",env->querystr("name"));
			tell_object(me, snprintf(msg, 255, index10[random(5)], me->querystr("tradepro/quest_npc_name"), me->querystr("tradepro/quest_killnpc_area"), me->querystr("tradepro/quest_killnpc_name")));
		}
		else
			tell_object(me, snprintf(msg, 255, index14[random(5)], me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_killnpc_name")));
		break;
	case 5://Ѳ��(����Ҫ����Ѳ��ʱ���ս��)
		me->set("tradepro/quest_killnpc_mp",env->querystr("area"));
		tell_object(me, snprintf(msg, 255, index5[random(5)], me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_killnpc_mp")));
		break;
		break;
	case 6://ʾ��
		me->set("tradepro/quest_killnpc_mp",index6[random(16)]);
		tell_object(me, snprintf(msg, 255, index6_1[random(5)], me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_killnpc_mp")));
		break;
	case 7://�ۼ�����
		r = load_room(me->querystr("corps/id"));
		enemy = r->querymap("list");
		if(! enemy) //����û�л�Ա��ı�����Ϊ����
		{
			if(me->query("tradepro/quest_count")>300)
				item_quest=load_item(index1[random(537)]);
			else
				item_quest=load_item(index1[random(300)]);
			me->set("tradepro/quest_item_name",item_quest->querystr("name"));
			me->set("tradepro/quest_item_id",item_quest->querystr("id"));
			me->set("tradepro/index",1);
			tell_object(me, snprintf(msg, 255, index1_1[random(5)], me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_item_name")));
		}
		else
		{
			CVector v;
			enemy->keys(v);
			me->set("tradepro/quest_killnpc_id",v[random(v.count())]);
			me->set("tradepro/quest_killnpc_name",enemy->querystr(v[random(v.count())]));
			if(r->query("index")==1)
			{
				CContainer * CorpsNpc;
				if(r->query("level")<3)
				{
					r=load_room(snprintf(msg, 255, "g1_���´��_%s",me->querystr("corps/id")));
					CorpsNpc=r->present("xinshang zhizhe");
				}
				else
				{
					r=load_room(snprintf(msg, 255, "g1_���ɸ�_%s",me->querystr("corps/id")));
					CorpsNpc=r->present("qing xia");
				}
				if(!CorpsNpc)
				{
					me->del("tradepro/quest_killnpc_id");
					me->del("tradepro/quest_killnpc_name");
					if(me->query("tradepro/quest_count")>300)
						item_quest=load_item(index1[random(537)]);
					else
						item_quest=load_item(index1[random(300)]);
					me->set("tradepro/quest_item_name",item_quest->querystr("name"));
					me->set("tradepro/quest_item_id",item_quest->querystr("id"));
					me->set("tradepro/index",1);
					tell_object(me, snprintf(msg, 255, index1_1[random(5)], me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_item_name")));
				}
				else
				{
					CorpsNpc->set(me->querystr("tradepro/quest_killnpc_id"),1);
					me->set("tradepro/quest_npc_id",CorpsNpc->querystr("id"));
					me->set("tradepro/quest_npc_name",CorpsNpc->querystr("name"));
					tell_object(me, snprintf(msg, 255, index7[random(5)], me->querystr("tradepro/quest_killnpc_name"), me->querystr("tradepro/quest_killnpc_id")));
				}
			}
		}
		break;
	case 8://���������Ϊ���ܾ��顢������
		me->set("tradepro/quest_pro_index",random(3)+1);
		i=me->query("level")*10+random(me->query("level"));
		switch(me->query("tradepro/quest_pro_index"))
		{
		case 1:
			me->set("tradepro/quest_pro_point",me->query("combat_exp")+i);
			tell_object(me, snprintf(msg, 255, index8[random(5)],  me->querystr("tradepro/quest_npc_name"),"�ܾ���",i));
			break;
		case 2:
			me->set("tradepro/quest_pro_point",me->query("repute")+i);
			tell_object(me, snprintf(msg, 255, index8[random(5)],  me->querystr("tradepro/quest_npc_name"),"����",i));
			break;
		case 3:
			me->set("tradepro/quest_pro_point",me->query("repute")-i);
			tell_object(me, snprintf(msg, 255, index8[random(5)], me->querystr("tradepro/quest_npc_name"),"����",-i));
			break;
		}
		break;
	case 9://Ѻ��
		tell_object(me, snprintf(msg, 255, index9[random(5)], me->querystr("tradepro/quest_npc_name")));
		break;
	case 11://�Ϲ�
		me->set("tradepro/quest_item_numer",random(50000)+10000+me->query("tradepro/quest_count")*10);
		tell_object(me, snprintf(msg, 255, index11[random(5)], me->querystr("tradepro/quest_npc_name"),me->query("tradepro/quest_item_numer")));
		break;
	case 12://�Ͷ���
		item_quest=load_item(index1[random(537)]);
		me->set("tradepro/quest_item_name",item_quest->querystr("name"));
		me->set("tradepro/quest_item_id",item_quest->querystr("id"));

		tradepro_item=load_item("tradepro_item");
		tradepro_item->set_name(item_quest->name(),item_quest->id());
		tradepro_item->move(me);
		destruct(item_quest);
		tell_object(me, snprintf(msg, 255, index12[random(5)], me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_item_name")));
		break;
	case 13://�ռ�����
		me->set("tradepro/quest_item_name",index13[random(32)]);
		me->set("tradepro/quest_item_numer",random(10)+5);
		tell_object(me, snprintf(msg, 255, index13_1[random(5)], me->querystr("tradepro/quest_npc_name"),me->query("tradepro/quest_item_numer"),me->querystr("tradepro/quest_item_name")));
		break;
	}
}

int CNpc::accept_object(CChar *me, CContainer *item)
{
	if(EQUALSTR(me->querystr("tradepro/quest_npc_id"),querystr("id")) )
	{
		if(current_time < me->query("tradepro/quest_time"))
		{
			char msg[255];
			if(me->query("tradepro/index")==1||me->query("tradepro/index")==12) //��\�Ͷ���
			{
				if(EQUALSTR(item->querystr("id"),me->querystr("tradepro/quest_item_id")))
				{
					say("��л������ˡ�",me);
					SendMenu(me);
					reward_tradepro(me);
					destruct(item);
					return 1;
				}
			}
			else if(me->query("tradepro/index")==4)//ץ��²
			{
				if(EQUALSTR(item->querystr("id"),me->querystr("tradepro/quest_killnpc_id"))
					&& item->Query(CChar::IS_NPC))
				{
					say("��л������ˡ�",me);
					SendMenu(me);
					reward_tradepro(me);
					destruct(item);
					return 1;
				}
			}
			else if(me->query("tradepro/index")==11)//�Ϲ�
			{
				if(EQUALSTR(item->querystr("id"),"coin") 
					&& item->query("value")==me->query("tradepro/quest_item_numer"))
				{
					say("��л������ˡ�",me);
					SendMenu(me);
					reward_tradepro(me);
					destruct(item);
					return 1;
				}
			}
			else if(me->query("tradepro/index")==13)//�ռ�����
			{
				if(EQUALSTR(item->querystr("name"),me->querystr("tradepro/quest_item_name")) )
				{
					say("��л������ˡ�",me);
					SendMenu(me);
					if(item->Query_Amount()>=me->query("tradepro/quest_item_numer"))
						reward_tradepro(me);
					else
					{
						me->add("tradepro/quest_item_numer",-item->Query_Amount());
						say(snprintf(msg, 255,"�鷳�����������ȥ�ռ�%d��%s���������ˡ�",
							me->query("tradepro/quest_item_numer"),me->querystr("tradepro/quest_item_name")));
						SendMenu(me);
					}
					destruct(item);
					return 1;
				}
			}
			else if(me->query("tradepro/index")==14)//�滭NPC����
			{
				if(EQUALSTR(item->querystr("id"),"mian ju") 
					&& EQUALSTR(item->querystr("apply/_id"),me->querystr("tradepro/quest_killnpc_id")))
				{
					say("��л������ˡ�",me);
					SendMenu(me);
					reward_tradepro(me);
					destruct(item);
					return 1;
				}
			}
		}
		else
		{
			say("������̫���ˣ����Ѿ�������Ҫ��İ����ˡ�",me);
			SendMenu(me);
			me->del("tradepro");
			return 1;
		}
	}
	return 0;
}

//��NPC���ӽ�Ǯ
void CNpc::add_money(LONG amount)
{
	CContainer * money;

	if(! amount) return;
	money = load_item("coin");
	money->set_amount(amount);
	money->move(this);
}

//���ò�ѯ����
void CNpc::set_inquiry(const char * ask, const char * answer, const char * topic)
{
	Inquiry_t * p = new Inquiry_t;

	if(topic) p->topic = topic;
	p->answer = answer;
	p->pFunc = NULL;
	m_listInquiry[ask] = p;
}

void CNpc::set_inquiry(const char * ask, INQUERYFUNC pFunc, const char * topic)
{
	Inquiry_t * p = new Inquiry_t;

	if(topic) p->topic = topic;
	p->pFunc = pFunc;
	m_listInquiry[ask] = p;
}

//���к��ĺ�ʽ
char * CNpc::greeting(CChar *me)
{
	return "";
}

//learn�õ�
int CNpc::recognize_apprentice(CChar *me)
{
	return 0;
}

//��NPC̸��
int CNpc::do_talk(CChar *me, char * ask)
{
	string msg;
	Inquiry_t * pInquiry;

	if(!me || !ask) return 0;
	
	//��������
	if(me->querymap("tradepro"))
	{
		if(EQUALSTR(me->querystr("tradepro/quest_npc_id"),querystr("id")))
		{
			if(current_time < me->query("tradepro/quest_time"))
			{
				switch(me->query("tradepro/index"))
				{
				case 2://����
					say("��л������ˡ�",me);
					SendMenu(me);
					reward_tradepro(me);
					break;
				case 3://ɱ��
					if(me->query("tradepro/quest_killnpc_ok"))
					{
						say("��л������ˡ�",me);
						SendMenu(me);
						reward_tradepro(me);
					}
					break;
				case 5://Ѳ��
					if(me->query("tradepro/quest_killnpc_ok"))
					{
						say("��л������ˡ�",me);
						SendMenu(me);
						reward_tradepro(me);
					}
					break;
				case 6://ʾ��
					if(me->query("tradepro/quest_killnpc_ok"))
					{
						say("��л������ˡ�",me);
						SendMenu(me);
						reward_tradepro(me);
					}
					break;
				case 7://�ۼ�����
					if(query(me->querystr("tradepro/quest_killnpc_id"))==99)
					{
						say("��л������ˡ�",me);
						SendMenu(me);
						reward_tradepro(me);
					}
					break;
				case 8://���������Ϊ���ܾ��顢������
					if(me->query("tradepro/quest_pro_index")==1 && me->query("combat_exp")>=me->query("tradepro/quest_pro_point"))
					{
						say("��л������ˡ�",me);
						SendMenu(me);
						reward_tradepro(me);
					}
					else if(me->query("tradepro/quest_pro_index")==2 && me->query("repute") >=me->query("tradepro/quest_pro_point"))
					{
						say("��л������ˡ�",me);
						SendMenu(me);
						reward_tradepro(me);
					}
					else if(me->query("tradepro/quest_pro_index")==3 && me->query("repute") <=me->query("tradepro/quest_pro_point"))
					{
						say("��л������ˡ�",me);
						SendMenu(me);
						reward_tradepro(me);
					}
					break;
				case 9://Ѻ��
					if(me->query("tradepro/quest_ok"))
					{
						say("��л������ˡ�",me);
						SendMenu(me);
						reward_tradepro(me);
					}
					break;
				case 10://����ĳNPCһ��ʱ�䲻��ɱ
					CChar * obj = find_npc(me->query("tradepro/quest_killnpc_object_id"));
					if(current_time >=me->query("tradepro/quest_killnpc_time"))
					{
						if(obj && obj->query("ok"))
						{
							obj->del("ok");
							say("��л������ˡ�",me);
							SendMenu(me);
							reward_tradepro(me);
						}
						else
						{
							say("����һ��С��Ҳ�����ã����Ѿ�������Ҫ���æ�ˡ�",me);
							SendMenu(me);
							me->del("tradepro");
							tell_object(me, "$HIR�������ʧ���ˡ�");
							return 1;
						}
					}
					break;
				}
			}
			else
			{
				say("������̫���ˣ����Ѿ�������Ҫ��İ����ˡ�",me);
				SendMenu(me);
				me->del("tradepro");
				return 1;
			}
		}
	}

	//��ѯask
	if(m_listInquiry.find(ask) == m_listInquiry.end())
	{
		//msg = greeting(me);	//�ȴ��к�
		//if(msg.length())
		//	say(msg.c_str(), me);

		if(! m_listInquiry.size())
		{
			return notify_fail("�Է�����Ը�����㡣");
		}

		LISTINQUIRY::iterator p;
		for(p = m_listInquiry.begin(); p!= m_listInquiry.end(); p++)
		{
			pInquiry = p->second;
			if(pInquiry->topic.length())
				AddMenuItem(pInquiry->topic.c_str(), p->first.c_str(), me);
			else
			{
				msg = "��";
				msg += name();
				msg += "��̹���";
				msg += p->first;
				msg += "�����⡣";
				AddMenuItem(msg.c_str(), p->first.c_str(), me);
			}
		}
		SendMenu(me);	
		return 1;
	}

	pInquiry = m_listInquiry[ask];
	
	if(pInquiry->pFunc)
	{
		const char * pRtn;

		pRtn = ( * pInquiry->pFunc)(this, me);

		if(pRtn && pRtn[0])
		{
			say(pRtn, me);
			SendMenu(me);
		}
	}
	else
	{
		say(pInquiry->answer.c_str(), me);
		SendMenu(me);
	}
	
	return 1;
}

void CNpc::random_move()
{
	if(! m_pEnvironment->Query(IS_ROOM)) return;

	CRoom * room = (CRoom *)m_pEnvironment;
	DTEXITLIST * list = room->query_exits();
		
	int doors = list->GetCount();
	if(doors)
	{
		char msg[80];
		POSITION p = list->FindIndex(random(doors));
		CDoor * dir = list->GetAt(p); 
		command(snprintf(msg, 80, "go 0 %s", dir->querystr("id")));
	}
}

//ʹ��cast target = 0:�Լ� 1:����
int CNpc::perform_action(char *magic, int target)
{
	char msg[255];
	CFightRoom * env;
	CChar * who = this;

	if(target && environment()->Query(IS_FIGHTROOM))
	{
		env = (CFightRoom *)environment();
		who = env->Select_Member(1 - query_team());
		if(! who) return 0;
	}

	return command(snprintf(msg, 255, "cast %ld %s", who->object_id(), magic));
}

int CNpc::accept_fight(CChar *me)
{
	char msg[255];
	string attr = querystr("attitude");
	
	if( query("hp") * 100 / query("max_hp") >= 90 ) 
	{
		if(attr == "friendly")
		{
			say(snprintf(msg, 255, "%s��ô������%s�Ķ��֣�", query_self(this), query_respect(me)), me);
			SendMenu(me);
			return 0;
		}
		else if(attr == "aggressive" || attr == "killer" )
		{
			say("�ߣ����аɣ�");
		}
		else if( ! is_fighting() )
		{
			say(snprintf(msg, 255, "��Ȼ%s�ͽ̣�%sֻ�÷��㡣", query_respect(me), query_self(this)));
		}
		set("hp", query("max_hp"));
		set("eff_hp", query("max_hp"));
		set("mp", query("max_mp"));
		return 1;
	} 
	
	return 0;
}

void CNpc::wield_weapon(char *weapon)
{
	char msg[80];
	CContainer * obj = present(weapon);
	if(! obj) return;
			
	if(! query_weapon())
		command(snprintf(msg, 80, "wield %ld", obj->object_id()));
}

void CNpc::unwield_weapon(char *weapon)
{
	char msg[80];
	CContainer * obj = present("bishou");
	if(! obj) return;

	if(obj == query_weapon())
		command(snprintf(msg, 80, "unwield %ld", obj->object_id()));
}


