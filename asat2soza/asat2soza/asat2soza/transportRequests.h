#pragma once

#ifndef H_TRANSPORT_REQUESTS
#define H_TRANSPORT_REQUESTS

#include <ctime>
#include <string>
#include <vector>

/*! Заявка на автотранспорт
 *
 */
class TransportRequestUnit {
public:
    struct tm      time_4_get_vehicle_; //! Дата и время подачи ТС
    unsigned int   passengers_numb_;    //! Количество пассажиров
    float          cargo_volume_; //! Объем груза: undefined => 0.0
    std::string    department_; //! Наименование структурного подразделения
    std::string    route_;  //! Маршрут
    std::string    adress_4_get_vehicle_;   //! Адрес подачи ТС
    std::string    category_vehicle_str_;   //! Категория ТС(текст)
    TransportRequestUnit() {
        //this->time_4_get_vehicle_ = struct tm() ;
    }

    TransportRequestUnit(const TransportRequestUnit& _Src_Request) {
        this->time_4_get_vehicle_ = _Src_Request.time_4_get_vehicle_; //! Дата и время подачи ТС
        this->passengers_numb_ = _Src_Request.passengers_numb_;    //! Количество пассажиров
        this->cargo_volume_ = _Src_Request.cargo_volume_; //! Объем груза: undefined => 0.0
        this->department_ = _Src_Request.department_; //! Наименование структурного подразделения
        this->route_ = _Src_Request.route_;  //! Маршрут
        this->adress_4_get_vehicle_ = _Src_Request.adress_4_get_vehicle_;   //! Адрес подачи ТС
        this->category_vehicle_str_ = _Src_Request.category_vehicle_str_;   //! Категория ТС(текст)
    }

    TransportRequestUnit(const time_t &      _time_4_get_vehicle,
                         const unsigned int  _passengers_numb = 0,
                         const float         _cargo_volume_ = 0,
                         const std::string & _department = "",
                         const std::string & _route = "",
                         const std::string & _adress_4_get_vehicle = "",
                         const std::string& _category_vehicle_str = ""
                        ) {
        
    }

    TransportRequestUnit& operator=(const TransportRequestUnit& _Src_Request) 
    {
        if (this == &_Src_Request)
            return *this;

        this->time_4_get_vehicle_ = _Src_Request.time_4_get_vehicle_; //! Дата и время подачи ТС
        this->passengers_numb_ = _Src_Request.passengers_numb_;    //! Количество пассажиров
        this->cargo_volume_ = _Src_Request.cargo_volume_; //! Объем груза: undefined => 0.0
        this->department_ = _Src_Request.department_; //! Наименование структурного подразделения
        this->route_ = _Src_Request.route_;  //! Маршрут
        this->adress_4_get_vehicle_ = _Src_Request.adress_4_get_vehicle_;   //! Адрес подачи ТС
        this->category_vehicle_str_ = _Src_Request.category_vehicle_str_;   //! Категория ТС(текст)
        return *this;
    }

};

/*! Заявка на автотранспорт (выгрузка АСАТ)
 *
 */
class TransportRequestUnitFull : public TransportRequestUnit {
public:
    std::string    request_numb_;   //! Номер заявки
    std::string    request_id_intro_;   //! Внутренний ИД заявки исполнителя
    std::string    status_description_; //! Описание статуса
    struct tm      time_return_vehicle_;    //! Время возвращения ТС
    std::string    priority_str_;  //! Приоритет (string)
    unsigned short priority_code_;  //! Приоритет (uint)
    std::string    request_type_str_;   //! Тип заявки
    std::string    employee_full_name_; //! ФИО сотрудника
    std::string    purpose_trip;    //! Цель поездки
             int   category_vehicle_code_;   //! Категория ТС(int)
    std::string    gosnomer_vehicle_;   //! госномер ТС
    std::string    setevoynomer_vehicle_;    //! сетевой номер ТС
    bool           is_intercity_;   //! междугороднаяя перевозка (признак)
             int   reject_reason_;  //! причина отказа
    std::string    reject_reason_str_;  //! причина отказа (текст) 
    std::string    answer_;  //! все поля с меткой Ответ: (разделены символом ';')
             int   affiliation_type_vehicle_;   //! Тип транспортного средства по принадлежн
    std::string    signature_pixmap_;   //! пиктограмма подписи
    std::string    signature_fullname_; //! ФИО подписавшего
    struct tm      signature_time_; //! дата и время подписи
    std::string    waybill_number_; //! Номер путевого листа
    struct tm      OTZ_time_beg_;   //! ОТЗ. дата и Время начала
    struct tm      OTZ_time_end_;   //! ОТЗ. дата и Время конца
    float          OTZ_timework_;   //! ОТЗ. Время работы на заказчика

    std::string    OTZ;  //! все поля с меткой Ответ: (разделены символом ';')
    bool           is_vehicle_not_RZD_; //! ТС не РЖД (признак)
    std::string    MTA_numb_executor_;  //! Номер МТА от Исполнителя
             int   area_department_;    //! Участок структурного подразделения
    std::string    violations_str_; //! Наименование нарушения при выполнении
             int   BE_; //! БЕ
    struct tm      request_time_;   //! Дата заявки
             int   request_ID_; //! ID заявки на перевозку
             int   request_status_; //! Статус заявки на перевозку
    struct tm      request_status_time_;   //! Дата и время заявки
    struct tm      work_time_;   //! Время работы на заказчика
    std::string    request_type_;   //! Тип заявки на перевозку
    std::string    voucher_status_; //! Статус проверки талона
    std::string    voucher_check_errors_;//! Ошибки при сверке талона
             int   region_code_;    //! Регион
    std::string    region_str_; //! Название региона
    std::string    motor_depot_str_;    //! Наименование автобазы/автоколонны
    bool           is_request_cancel_by_deadline_;  //! Заявка отменена с нарушением сроков

    //TransportRequestUnitFull(TransportRequestUnitFull & _Src_Request) {
    //    
    //}

    TransportRequestUnitFull(TransportRequestUnitFull & _Src_Request) {
        this->request_numb_ = _Src_Request.request_numb_;   //! Номер заявки
        this->request_id_intro_ = _Src_Request.request_id_intro_;   //! Внутренний ИД заявки исполнителя
        this->status_description_ = _Src_Request.status_description_; //! Описание статуса
        this->time_return_vehicle_ = _Src_Request.time_return_vehicle_;    //! Время возвращения ТС
        this->priority_str_ = _Src_Request.priority_str_;  //! Приоритет (string)
        this->priority_code_ = _Src_Request.priority_code_;  //! Приоритет (uint)
        this->request_type_str_ = _Src_Request.request_type_str_;   //! Тип заявки
        this->employee_full_name_ = _Src_Request.employee_full_name_; //! ФИО сотрудника
        this->purpose_trip = _Src_Request.purpose_trip;    //! Цель поездки
        this->category_vehicle_code_ = _Src_Request.category_vehicle_code_;   //! Категория ТС(int)
        this->gosnomer_vehicle_ = _Src_Request.gosnomer_vehicle_;   //! госномер ТС
        this->setevoynomer_vehicle_ = _Src_Request.setevoynomer_vehicle_;    //! сетевой номер ТС
        this->is_intercity_ = _Src_Request.is_intercity_;   //! междугороднаяя перевозка (признак)
        this->reject_reason_ = _Src_Request.reject_reason_;  //! причина отказа
        this->reject_reason_str_ = _Src_Request.reject_reason_str_;  //! причина отказа (текст) 
        this->answer_ = _Src_Request.answer_;  //! все поля с меткой Ответ: (разделены символом ';')
        this->affiliation_type_vehicle_ = _Src_Request.affiliation_type_vehicle_;   //! Тип транспортного средства по принадлежн
        this->signature_pixmap_ = _Src_Request.signature_pixmap_;   //! пиктограмма подписи
        this->signature_fullname_ = _Src_Request.signature_fullname_; //! ФИО подписавшего
        this->signature_time_ = _Src_Request.signature_time_; //! дата и время подписи
        this->waybill_number_ = _Src_Request.waybill_number_; //! Номер путевого листа
        this->OTZ_time_beg_ = _Src_Request.OTZ_time_beg_;   //! ОТЗ. дата и Время начала
        this->OTZ_time_end_ = _Src_Request.OTZ_time_end_;   //! ОТЗ. дата и Время конца
        this->OTZ_timework_ = _Src_Request.OTZ_timework_;   //! ОТЗ. Время работы на заказчика

        this->OTZ = _Src_Request.OTZ;  //! все поля с меткой Ответ: (разделены символом ';')
        this->is_vehicle_not_RZD_ = _Src_Request.is_vehicle_not_RZD_; //! ТС не РЖД (признак)
        this->MTA_numb_executor_ = _Src_Request.MTA_numb_executor_;  //! Номер МТА от Исполнителя
        this->area_department_ = _Src_Request.area_department_;    //! Участок структурного подразделения
        this->violations_str_ = _Src_Request.violations_str_; //! Наименование нарушения при выполнении
        this->BE_ = _Src_Request.BE_; //! БЕ
        this->request_time_ = _Src_Request.request_time_;   //! Дата заявки
        this->request_ID_ = _Src_Request.request_ID_; //! ID заявки на перевозку
        this->request_status_ = _Src_Request.request_status_; //! Статус заявки на перевозку
        this->request_status_time_ = _Src_Request.request_status_time_;   //! Дата и время заявки
        this->work_time_ = _Src_Request.work_time_;   //! Время работы на заказчика
        this->request_type_ = _Src_Request.request_type_;   //! Тип заявки на перевозку
        this->voucher_status_ = _Src_Request.voucher_status_; //! Статус проверки талона
        this->voucher_check_errors_ = _Src_Request.voucher_check_errors_;//! Ошибки при сверке талона
        this->region_code_ = _Src_Request.region_code_;    //! Регион
        this->region_str_ = _Src_Request.region_str_; //! Название региона
        this->motor_depot_str_ = _Src_Request.motor_depot_str_;    //! Наименование автобазы/автоколонны
        this->is_request_cancel_by_deadline_ = _Src_Request.is_request_cancel_by_deadline_;  //! Заявка отменена с нарушением сроков
    }

    TransportRequestUnitFull& operator=(const TransportRequestUnitFull & _Src_Request)
    {
        if (this == &_Src_Request)
            return *this;

        this->request_numb_ = _Src_Request.request_numb_;   //! Номер заявки
        this->request_id_intro_ = _Src_Request.request_id_intro_;   //! Внутренний ИД заявки исполнителя
        this->status_description_ = _Src_Request.status_description_; //! Описание статуса
        this->time_return_vehicle_ = _Src_Request.time_return_vehicle_;    //! Время возвращения ТС
        this->priority_str_ = _Src_Request.priority_str_;  //! Приоритет (string)
        this->priority_code_ = _Src_Request.priority_code_;  //! Приоритет (uint)
        this->request_type_str_ = _Src_Request.request_type_str_;   //! Тип заявки
        this->employee_full_name_ = _Src_Request.employee_full_name_; //! ФИО сотрудника
        this->purpose_trip = _Src_Request.purpose_trip;    //! Цель поездки
        this->category_vehicle_code_ = _Src_Request.category_vehicle_code_;   //! Категория ТС(int)
        this->gosnomer_vehicle_ = _Src_Request.gosnomer_vehicle_;   //! госномер ТС
        this->setevoynomer_vehicle_ = _Src_Request.setevoynomer_vehicle_;    //! сетевой номер ТС
        this->is_intercity_ = _Src_Request.is_intercity_;   //! междугороднаяя перевозка (признак)
        this->reject_reason_ = _Src_Request.reject_reason_;  //! причина отказа
        this->reject_reason_str_ = _Src_Request.reject_reason_str_;  //! причина отказа (текст) 
        this->answer_ = _Src_Request.answer_;  //! все поля с меткой Ответ: (разделены символом ';')
        this->affiliation_type_vehicle_ = _Src_Request.affiliation_type_vehicle_;   //! Тип транспортного средства по принадлежн
        this->signature_pixmap_ = _Src_Request.signature_pixmap_;   //! пиктограмма подписи
        this->signature_fullname_ = _Src_Request.signature_fullname_; //! ФИО подписавшего
        this->signature_time_ = _Src_Request.signature_time_; //! дата и время подписи
        this->waybill_number_ = _Src_Request.waybill_number_; //! Номер путевого листа
        this->OTZ_time_beg_ = _Src_Request.OTZ_time_beg_;   //! ОТЗ. дата и Время начала
        this->OTZ_time_end_ = _Src_Request.OTZ_time_end_;   //! ОТЗ. дата и Время конца
        this->OTZ_timework_ = _Src_Request.OTZ_timework_;   //! ОТЗ. Время работы на заказчика

        this->OTZ = _Src_Request.OTZ;  //! все поля с меткой Ответ: (разделены символом ';')
        this->is_vehicle_not_RZD_ = _Src_Request.is_vehicle_not_RZD_; //! ТС не РЖД (признак)
        this->MTA_numb_executor_ = _Src_Request.MTA_numb_executor_;  //! Номер МТА от Исполнителя
        this->area_department_ = _Src_Request.area_department_;    //! Участок структурного подразделения
        this->violations_str_ = _Src_Request.violations_str_; //! Наименование нарушения при выполнении
        this->BE_ = _Src_Request.BE_; //! БЕ
        this->request_time_ = _Src_Request.request_time_;   //! Дата заявки
        this->request_ID_ = _Src_Request.request_ID_; //! ID заявки на перевозку
        this->request_status_ = _Src_Request.request_status_; //! Статус заявки на перевозку
        this->request_status_time_ = _Src_Request.request_status_time_;   //! Дата и время заявки
        this->work_time_ = _Src_Request.work_time_;   //! Время работы на заказчика
        this->request_type_ = _Src_Request.request_type_;   //! Тип заявки на перевозку
        this->voucher_status_ = _Src_Request.voucher_status_; //! Статус проверки талона
        this->voucher_check_errors_ = _Src_Request.voucher_check_errors_;//! Ошибки при сверке талона
        this->region_code_ = _Src_Request.region_code_;    //! Регион
        this->region_str_ = _Src_Request.region_str_; //! Название региона
        this->motor_depot_str_ = _Src_Request.motor_depot_str_;    //! Наименование автобазы/автоколонны
        this->is_request_cancel_by_deadline_ = _Src_Request.is_request_cancel_by_deadline_;  //! Заявка отменена с нарушением сроков
        return *this;
    }
    int parseRequest(const std::string & str_str);
};

class TransporRequestsList {
public:
    std::vector<TransportRequestUnitFull> list_requests;
    int readFileWithTabDelim(const std::string & filename);

};


#endif //! H_TRANSPORT_REQUESTS